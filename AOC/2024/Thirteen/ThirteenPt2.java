import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThirteenPt2 {
    public static void main(String[] args) throws IOException {
        ArrayList<long[]> eqX = new ArrayList<>();
        ArrayList<long[]> eqY = new ArrayList<>();
        long[] tmpEqX = new long[3];
        long[] tmpEqY = new long[3];
        long total = 0;

        List<Long> input = Arrays.asList(
                Files.readString(Paths.get("thirteen.txt"))
                .strip()
                .replaceAll("[^0-9,\n\r]", "")
                .split("[\n\r,]+")
            )
            .stream()
            .map(Long::parseLong)
            .toList();

        for(int i = 0; i < input.size(); i += 2){
            int spot = (i / 2) % 3;
            tmpEqX[spot] = input.get(i); 
            tmpEqY[spot] = input.get(i + 1);
            
            if (spot >= 2){
                tmpEqX[spot] += 10000000000000L;
                tmpEqY[spot] += 10000000000000L;
                eqX.add(tmpEqX.clone());
                eqY.add(tmpEqY.clone());
                tmpEqX = new long[3];
                tmpEqY = new long[3];
            }
        }

        for(int i = 0; i < eqX.size(); i++){
            long[] x = eqX.get(i);
            long[] y = eqY.get(i);

            if(x[0] == y[0] && x[1] == y[1]){
                if(x[2] != y[2]) continue;
                double min = (double)x[2] / (double)(x[0] + x[1]);
                if(min % 1 == 0) total += (long) min;
                continue;
            }

            long tmpx = x[0];
            long tmpy = y[0];
            for(int j = 0; j < 3; j++){
                x[j] *= tmpy;
                y[j] *= tmpx;
            }

            double b = (double)(x[2] - y[2]) / (double)(x[1] - y[1]);
            double a = ((double)(x[2] - (x[1] * b)) / (double)x[0]);
            if(a < 0 || b < 0) continue;
            if(a % 1 == 0 && b % 1 == 0) total += (long)b + (long)a * 3;
        }
        System.out.println(total);
    }
}
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class EightPt2{
    private static List<String> input;
    private static int[][] antinodes;
    public static void main(String[] args) throws IOException{
        input = Files.readAllLines(Paths.get("eight.txt"));
        antinodes = new int[input.size()][input.get(0).length()];

        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input.get(i).length(); j++){
                char current = input.get(i).charAt(j);
                if(('a' <= current && current <= 'z') ||
                   ('A' <= current && current <= 'Z') ||
                   ('0' <= current && current <='9')) instancesAfter(current, new int[]{i, j});
            }
        }
        int count = 0;
        for(int[] row : antinodes){
            for(int location : row){
                if(location >= 1) count++;
            }
        }
        System.out.println(count);
    }

    private static void instancesAfter(char current, int[] location){
        int index = location[1] + 1;
        for(int i = location[0]; i < input.size(); i++){
            while(index != -1){
                index = input.get(i).indexOf(current, index);
                if(index != -1){
                    checkAll(location, new int[]{i, index});
                    index++;
                }
            }
            index = 0;
        }
    }
    
    private static void checkAll(int[] p1, int[] p2){
        int[] change = {p2[0] - p1[0], p2[1] - p1[1]};
        int gcd = GCD(change[0], change[1]);
        change = new int[]{change[0] / gcd, change[1] / gcd};
        int[] temp = {p1[0], p1[1]};

        antinodes[p1[0]][p1[1]]++;
        while(insideSquare(temp)){
            temp[0] += change[0];
            temp[1] += change[1];

            if(insideSquare(temp)) antinodes[temp[0]][temp[1]]++;
        }
        temp = new int[]{p1[0], p1[1]};
        while(insideSquare(temp)){
            temp[0] -= change[0];
            temp[1] -= change[1];

            if(insideSquare(temp)) antinodes[temp[0]][temp[1]]++;
        }
    }

    private static boolean insideSquare(int[] p){
        return 0 <= p[0] && p[0] < input.size() && 0 <= p[1] && p[1] < input.get(0).length();
    }

    private static int GCD(int a, int b){
        if (b == 0) return a;
        return GCD(b, a % b);
     }
}
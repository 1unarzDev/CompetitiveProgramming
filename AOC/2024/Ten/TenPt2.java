import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class TenPt2{
    private static int[][] topo;
    private static int count;
    public static void main(String[] args) throws IOException {
        List<String> input = Files.readAllLines(Paths.get("ten.txt"));
        topo = new int[input.size()][input.get(0).length()];
        int total = 0;

        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input.get(i).length(); j++)
                topo[i][j] = input.get(i).charAt(j) - 48;
        }

        for (int i = 0; i < topo.length; i++) {
            for (int j = 0; j < topo[i].length; j++) {
                if(topo[i][j] == 0){
                    findTrails(new int[]{i, j}, new int[]{-1, -1});
                    total += count;
                    count = 0;
                }
            }
        }

        System.out.println(total);
    }

    private static void findTrails(int[] pt, int[] prevPt) {
        if (topo[pt[0]][pt[1]] == 9) {
            count++;
            return;
        }
        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int[] direction : directions) {
            int[] nextPt = new int[]{pt[0] + direction[0], pt[1] + direction[1]};
            if (nextPt[0] < 0 || topo.length <= nextPt[0] || nextPt[1] < 0 || topo[nextPt[0]].length <= nextPt[1]) continue;
            if (nextPt[0] == prevPt[0] && nextPt[1] == prevPt[1]) continue;
            if (topo[nextPt[0]][nextPt[1]] != topo[pt[0]][pt[1]] + 1) continue;
            findTrails(nextPt, pt);
        }
    }
}
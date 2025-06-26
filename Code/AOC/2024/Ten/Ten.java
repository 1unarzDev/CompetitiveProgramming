import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;

public class Ten {
    private static int[][] topo;
    private static Set<Point> peaks = new HashSet<>();
    private static int[][] out;

    public static void main(String[] args) throws IOException {
        List<String> input = Files.readAllLines(Paths.get("ten.txt"));
        topo = new int[input.size()][input.get(0).length()];
        out = new int[input.size()][input.get(0).length()];
        int total = 0;

        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input.get(i).length(); j++){ 
                topo[i][j] = input.get(i).charAt(j) - 48;
                out[i][j] = 0;
            }
        }

        for (int i = 0; i < topo.length; i++) {
            for (int j = 0; j < topo[i].length; j++) {
                if(topo[i][j] == 0){
                    findTrails(new Point(i, j), new Point(-1, -1));
                    out[i][j] += peaks.size();
                    total += peaks.size();
                    peaks.clear();
                }
            }
        }

        FileWriter writer = new FileWriter("out.txt");
        StringBuilder sb = new StringBuilder();
        for(int[] row : out){
            for(int item : row) sb.append((item < 100 ? (item < 10 ? (item < 1 ? "   " : "  " + item) : " " + item) : "")).append(" ");
            writer.write(sb.toString() + "\n");
            sb.setLength(0);
        }
        writer.close();

        System.out.println(total);
    }

    private static void findTrails(Point pt, Point prevPt) {
        if (topo[pt.y][pt.x] == 9) {
            peaks.add(pt);
            return;
        }
        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int[] direction : directions) {
            Point nextPt = new Point(pt.y + direction[0], pt.x + direction[1]);
            if (nextPt.y < 0 || topo.length <= nextPt.y || nextPt.x < 0 || topo[nextPt.y].length <= nextPt.x) continue;
            if (nextPt.equals(prevPt)) continue;
            if (topo[nextPt.y][nextPt.x] != topo[pt.y][pt.x] + 1) continue;
            findTrails(nextPt, pt);
        }
    }

    private static class Point {
        int x, y;

        Point(int y, int x) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}
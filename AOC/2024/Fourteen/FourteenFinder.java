import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.TreeMap;

public class FourteenFinder {
    private static final Pos GRID_DIMENSIONS = new Pos(101, 103);
    public static void main(String[] args) throws IOException {
        List<Robot> robots = Files.readAllLines(Paths.get("fourteen.txt"))
                                  .stream()
                                  .map(s -> s.replaceAll("[^\\d-]", " ").trim())
                                  .map(s -> Arrays.stream(s.split("\\s+"))
                                                  .map(Integer::parseInt)
                                                  .toList())
                                  .map(Robot::createRobot)
                                  .toList();

        int[] directions = {1, 0, -1, -1, 0, 1, 1, -1, 1};
        Map<Integer, Integer> clusterScores = new TreeMap<>();
        for(int i = 1; i <= 10000; i++){
            int cluster = 0;
            for(int j = 0; j < robots.size(); j++){
                Robot r = robots.get(j);
                r.move(1);
                for(int k = 0; k < directions.length - 1; k++){
                    Pos direction = new Pos(r.pos.x + directions[k], r.pos.y + directions[k + 1]);
                    if(robots.stream().anyMatch(rb -> rb.pos.equals(direction))) cluster++;
                }
            }
            clusterScores.put(cluster, i);

            FileWriter writer = new FileWriter("Images/out" + i + ".txt");
            StringBuilder sb = new StringBuilder();
            Set<Pos> robotPositions = new HashSet<>();
            for (Robot r : robots) {
                robotPositions.add(r.pos);
            }
            
            for (int j = 0; j < GRID_DIMENSIONS.x; j++) {
                for (int k = 0; k < GRID_DIMENSIONS.y; k++) {
                    Pos p = new Pos(j, k);
                    sb.append(robotPositions.contains(p) ? "#" : " ");
                }
                sb.append("\n");
            }
            
            writer.write(sb.toString());
            writer.close();
        }

        List<Integer> keys = new ArrayList<>(clusterScores.keySet());
        Collections.sort(keys);
        for(int key : keys) System.out.println(clusterScores.get(key));
    }

    private static class Robot {
        private Pos pos, vel;

        private static Robot createRobot(List<Integer> values) {
            return new Robot(values.get(0), values.get(1), values.get(2), values.get(3));
        }

        public Robot(int x, int y, int vX, int vY) {
            this.pos = new Pos(x, y);
            this.vel = new Pos(vX, vY);
        }

        public void move(int moves){
            pos.x = ((pos.x + moves * vel.x) % GRID_DIMENSIONS.x + GRID_DIMENSIONS.x) % GRID_DIMENSIONS.x;
            pos.y = ((pos.y + moves * vel.y) % GRID_DIMENSIONS.y + GRID_DIMENSIONS.y) % GRID_DIMENSIONS.y;
        }

        @Override
        public String toString(){
            return "Robot: " + pos + ", " + vel;
        } 
    }

    private static class Pos {
        private int x, y;

        public Pos(int x, int y) {
            this.x = x; 
            this.y = y;
        }

        @Override
        public String toString(){
            return "(" + x + ", " + y + ")";
        } 

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pos pos = (Pos) o;
            return x == pos.x && y == pos.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}

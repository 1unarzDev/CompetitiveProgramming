import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;

public class Fourteen {
    private static final int SECONDS = 100;
    private static final Pos GRID_DIMENSIONS = new Pos(101, 103);
    public static void main(String[] args) throws IOException {
        int[] quadrants = new int[4];
        List<Robot> robots = Files.readAllLines(Paths.get("fourteen.txt"))
                                  .stream()
                                  .map(s -> s.replaceAll("[^\\d-]", " ").trim())
                                  .map(s -> Arrays.stream(s.split("\\s+"))
                                                  .map(Integer::parseInt)
                                                  .toList())
                                  .map(Robot::createRobot)
                                  .toList();

        for(Robot r : robots){
            r.move(SECONDS);
            int q = findQuadrant(r);
            if(q != -1) quadrants[q - 1]++;
        }

        System.out.println(quadrants[0] * quadrants[1] * quadrants[2] * quadrants[3]);
    }

    private static int findQuadrant(Robot r){
        if(r.pos.y == GRID_DIMENSIONS.y / 2 || r.pos.x == GRID_DIMENSIONS.x / 2) return -1;

        if(r.pos.y < GRID_DIMENSIONS.y / 2) {
            if(r.pos.x > GRID_DIMENSIONS.x / 2) return 1;
            return 2;
        }

        if(r.pos.x < GRID_DIMENSIONS.x / 2) return 3;
        return 4;
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
    }
}

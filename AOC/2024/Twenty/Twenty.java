import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.stream.Collectors;

public class Twenty {
    private static Point goal;
    private static Point start;
    private static PriorityQueue<Point> open = new PriorityQueue<>(Comparator.comparingInt(p -> p.weightedCost));
    private static Map<Point, Integer> closed = new HashMap<>();
    private static ArrayList<Integer> scores = new ArrayList<>();
    private static int[] directions = {1, 0, -1, 0, 1};
    public static void main(String[] args) throws IOException {
        char[][] map = Files.readAllLines(Paths.get("eighteen.txt"))
                                     .stream()
                                     .map(str -> str.split(","))
                                     .map(arr -> toPoint(Arrays.stream(arr)
                                                               .mapToInt(Integer::parseInt)
                                                               .toArray()))
                                     .collect(Collectors.toList());

        for(int i = 2; i < map.length - 2; i++){
            for(int j = 2; j < map[i].length - 2; j++){
                map[i][j] = ".";
                length = aStarSearch();
            }  
        }
            open.clear();
            closed.clear();
    
        System.out.println(remaining.get(blocks - 2));
    }

    private static int aStarSearch(){
        Point current;
        open.add(start);
        while(!open.isEmpty()){
            current = open.poll();
            if(current.equals(goal)) return current.cost;
            successors(current);
            closed.put(current, current.weightedCost);
        }
        return -1;
    }

    private static void successors(Point pt){
        for(int i = 0; i < directions.length - 1; i++){
            Point successor = new Point(pt.y + directions[i], pt.x + directions[i + 1], pt);
            if(isValid(successor) && isBest(successor)) open.add(successor);
        }
    }

    private static boolean isValid(Point pt){
        return !blocked.contains(pt) && 0 <= pt.x && pt.x <= goal.x && 0 <= pt.y && pt.y <= goal.y;
    }

    private static boolean isBest(Point pt){
        return !closed.containsKey(pt) || pt.weightedCost < closed.get(pt);
    }

    private static Point toPoint(int[] pt){
        return new Point(pt[0], pt[1]);
    }

    private static class Point {
        final int y, x, cost, weightedCost;

        Point(int y, int x) {
            this(y, x, null);
        }
    
        Point(int y, int x, Point parent) {
            this.y = y;
            this.x = x;
            this.cost = (parent == null ? 0 : parent.cost + 1);
            int heuristic = (parent == null ? 0 : Math.abs(goal.x - this.x) + Math.abs(goal.y - this.y));
            this.weightedCost = heuristic + this.cost;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return y == point.y && x == point.x;
        }

        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }

        @Override
        public String toString(){
            return "(" + y + ", " + x + ")";
        }
    }
}
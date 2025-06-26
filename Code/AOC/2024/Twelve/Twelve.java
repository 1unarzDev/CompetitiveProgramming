import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Twelve {
    private static int[] directions = new int[]{1, 0, -1, 0, 1};
    private static Set<Plant> checked = new HashSet<>();
    private static Map<Integer, Group> groups = new HashMap<>();
    private static char[][] map;
    public static void main(String[] args) throws IOException {
        map = Files.readAllLines(Paths.get("twelve.txt")).stream()
                                                         .map(String::toCharArray)
                                                         .toArray(char[][]::new);

        int id = 0;
        for(int i = 0; i < map.length; i++){
            for(int j = 0; j < map[i].length; j++){
                Plant location = new Plant(i, j, map[i][j]);
                if(checked.contains(location)) continue;
                groups.put(id, new Group(0, 0));
                searchGroup(location, id);
                id++;
            }
        }

        int total = 0;
        for(Integer group : groups.keySet()){
            total += groups.get(group).perimeter * groups.get(group).area;
        }
        System.out.println(total);
    }

    private static void searchGroup(Plant location, int id) {
        checked.add(location);
        groups.get(id).area++;

        for(int i = 0; i < directions.length - 1; i++){
            int y = location.y + directions[i];
            int x = location.x + directions[i + 1];
            if(!isValid(y, x)) {
                groups.get(id).perimeter++;
                continue;
            }
            Plant newLocation = new Plant(y, x, map[y][x]);
            if(newLocation.type != location.type){
                groups.get(id).perimeter++;
                continue;
            }
            if(checked.contains(newLocation)) continue;
            searchGroup(newLocation, id);
        }
    }

    private static boolean isValid(int y, int x){
        return 0 <= y && y < map.length && 0 <= x && x < map[y].length;
    }

    private static class Group {
        int area, perimeter;

        Group(int area, int perimeter) {
            this.area = area;
            this.perimeter = perimeter;
        }
    }

    private static class Plant {
        int y, x;
        char type;

        Plant(int y, int x, char type) {
            this.y = y;
            this.x = x;
            this.type = type;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Plant Plant = (Plant) o;
            return y == Plant.y && x == Plant.x;
        }

        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }

        @Override
        public String toString() {
            return "(" + y + ", " + x + ")";
        }
    }
}
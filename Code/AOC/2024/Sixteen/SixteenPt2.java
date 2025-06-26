import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class SixteenPt2 {
    private static Long minScore = Long.MAX_VALUE;
    private static char[][] map;
    private static Map<YXD, Long> optimal = new HashMap<>();
    private static Map<Long, Integer> paths = new HashMap<>();

    public static void main(String[] args) throws IOException {
        YXD start = new YXD(-1, -1, -1);

        map = Files.readAllLines(Paths.get("sixteen.txt"))
            .stream()
            .map(String::toCharArray)
            .toArray(char[][]::new);

        for(int i = 0; i < map.length; i++){
            for(int j = 0; j < map[i].length; j++){
                if(map[i][j] == 'S'){
                    start.y = i;
                    start.x = j;
                    start.dir = 0;
                }
            }
        }
        
        Reindeer rd = new Reindeer(start, 0, 0);
        branch(rd);
        System.out.println(paths.get(minScore));
    }

    private static void branch(Reindeer rd){
        while(true){
            if(rd.score > minScore) return; 
            YXD ref = new YXD(rd.state.y, rd.state.x, rd.state.dir);
            if(optimal.containsKey(ref) && optimal.get(ref) < rd.score) return;
            else optimal.put(ref, rd.score);
            if(map[rd.state.y][rd.state.x] == 'E'){ 
                if(rd.score < minScore) minScore = rd.score;
                if(!paths.containsKey(rd.score)) paths.put(rd.score, rd.passed);
                else paths.put(rd.score, paths.get(rd.score) + rd.passed);
                return;
            }
            if(rd.atDir((rd.state.dir + 1) % 4) == '.'){
                Reindeer newRd = rd.copy();
                newRd.state.dir = (newRd.state.dir + 1) % 4;
                newRd.score += 1000;
                newRd.move();
                branch(newRd);
            }
            if(rd.atDir((rd.state.dir + 3) % 4) == '.'){
                Reindeer newRd = rd.copy();
                newRd.state.dir = (newRd.state.dir + 3) % 4;
                newRd.score += 1000;
                newRd.move();
                branch(newRd);
            }
            if(rd.atDir(rd.state.dir) == '#') return;
            rd.move();
        }
    }

    private static class Reindeer {
        public YXD state;
        public long score;
        public int passed;

        public Reindeer(YXD state, long score, int passed){
            this.state = state;
            this.score = score;
            this.passed = passed;
        }

        public void move(){
            switch(state.dir){
                case 0 -> state.x++;
                case 1 -> state.y++;
                case 2 -> state.x--;
                case 3 -> state.y--;
            }
            score++;
            passed++;
        }

        public char atDir(int dir){
            switch(dir){
                case 0 -> {return map[state.y][state.x + 1];}
                case 1 -> {return map[state.y + 1][state.x];}
                case 2 -> {return map[state.y][state.x - 1];}
                case 3 -> {return map[state.y - 1][state.x];}
            }
            return '-';
        }

        public Reindeer copy(){
            return new Reindeer(new YXD(state.y, state.x, state.dir), score, passed);
        }
    }

    private static class YXD {
        int y, x;
        int dir;

        YXD(int y, int x, int dir){
            this.y = y;
            this.x = x;
            this.dir = dir;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            YXD YXD = (YXD) o;
            return y == YXD.y && x == YXD.x && dir == YXD.dir;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y, dir);
        }
    }
}
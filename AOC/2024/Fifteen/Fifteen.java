import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Fifteen {
    public static void main(String[] args) throws IOException {
        char[][] map = Files.readAllLines(Paths.get("map.txt"))
            .stream()
            .map(String::toCharArray)
            .toArray(char[][]::new);
        char[] moves = Files.readString(Paths.get("moves.txt")).trim().toCharArray();
        int[] robot = new int[]{-1, -1};
        for(int i = 0; i < map.length; i++) for(int j = 0; j < map[i].length; j++) if(map[i][j] == '@') robot = new int[]{i, j};

        for(char move : moves){
            switch(move){
                case('^') -> {
                    int last = robot[0];
                    int c = robot[1];
                    while(map[last][c] != '.' && map[last][c] != '#') last--;
                    if(map[last][c] == '#') continue;
                    for(int i = last; i < robot[0] - 1; i++) map[i][c] = 'O';
                    map[robot[0]][c] = '.';
                    map[robot[0] - 1][c] = '@';
                    robot[0]--;
                }
                case('>') -> {
                    int last = robot[1];
                    int r = robot[0];
                    while(map[r][last] != '.' && map[r][last] != '#') last++;
                    if(map[r][last] == '#') continue;
                    for(int i = last; i > robot[1] + 1; i--) map[r][i] = 'O';
                    map[r][robot[1]] = '.';
                    map[r][robot[1] + 1] = '@';
                    robot[1]++;
                }
                case('v') -> {
                    int last = robot[0];
                    int c = robot[1];
                    while(map[last][c] != '.' && map[last][c] != '#') last++;
                    if(map[last][c] == '#') continue;
                    for(int i = last; i > robot[0] + 1; i--) map[i][c] = 'O';
                    map[robot[0]][c] = '.';
                    map[robot[0] + 1][c] = '@';
                    robot[0]++;
                }
                case('<') -> {
                    int last = robot[1];
                    int r = robot[0];
                    while(map[r][last] != '.' && map[r][last] != '#') last--;
                    if(map[r][last] == '#') continue;
                    for(int i = last; i < robot[1] - 1; i++) map[r][i] = 'O';
                    map[r][robot[1]] = '.';
                    map[r][robot[1] - 1] = '@';
                    robot[1]--;
                }
            }
        }

        int total = 0;
        for(int i = 0; i < map.length; i++)
            for(int j = 0; j < map[i].length; j++) 
                if(map[i][j] == 'O') total += i * 100 + j;

        System.out.println(total);
    }
}
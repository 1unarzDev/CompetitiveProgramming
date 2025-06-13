import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Eight {
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
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input.get(i).length(); j++){
                if(p1[0] - i == (p2[0] - i) * 2 &&
                   p1[1] - j == (p2[1] - j) * 2) antinodes[i][j]++;
                else if ((p1[0] - i) * 2 == p2[0] - i &&
                         (p1[1] - j) * 2 == p2[1] - j) antinodes[i][j]++;
            }
        }
    }
}

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TwentyOne {
    final private static char[][] NUM_PAD_REF = {{'7', '8', '9'},
                                                 {'4', '5', '6'},
                                                 {'1', '2', '3'},
                                                 {'.', '0', 'A'}};
    final private static char[][] KEY_PAD_REF = {{'.', '^', 'A'},
                                                 {'<', 'v', '>'}};
    final private static int KEY_PAD_NUM = 2;

    final private static Map<Character, int[]> np = new HashMap<>();
    final private static Map<Character, int[]> kp = new HashMap<>();
    public static void main(String[] args) throws IOException {
        makeMap();

        List<String> sequences = Files.readAllLines(Paths.get("twentyOne.txt"));
        int total = 0;
        for(String sequence : sequences){
            int cost = 0;
            for(int i = 0; i < sequence.length() - 1; i++) {
                cost += getCost(sequence.charAt(i), sequence.charAt(i + 1));
            }
            total += cost * Integer.parseInt(sequence.substring(0, sequence.length() - 1));
        }
        System.out.println(total);
    }

    private static void makeMap(){
        for(int i = 0; i < NUM_PAD_REF.length; i++){
            for(int j = 0; j < NUM_PAD_REF[i].length; j++){
                np.put(NUM_PAD_REF[i][j], new int[]{i, j});
            }
        }

        for(int i = 0; i < KEY_PAD_REF.length; i++){
            for(int j = 0; j < KEY_PAD_REF[i].length; j++){
                kp.put(KEY_PAD_REF[i][j], new int[]{i, j});
            }
        }
    }


    private static int getCost(char from, char to){
        return dist(np.get(from), np.get(to));
    }

    private static ArrayList<Character> getActions(char action){
        ArrayList<Character> actions = new ArrayList();

        actions.add('A');
        return actions;
    }

    private static int[] moves(int[] p1, int[] p2){
        return new int[]{p2[0] - p1[0], p2[1] - p2[1]};
    }

    private static int dist(int[] p1, int[] p2){
        return Math.abs(p2[0] - p1[0]) + Math.abs(p2[1] - p1[1]);
    }
}

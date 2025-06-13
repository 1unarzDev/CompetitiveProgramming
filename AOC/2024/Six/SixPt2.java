import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;

public class SixPt2{
    private static List<String> room;
    private static int[][] traveled;
    private static int[] guard = {-1, -1};
    private static int direction = 5;
    private static int total = 0;
    private static boolean blocked = false;

    public static void main(String[] args) throws IOException{
        room = Files.readAllLines(Paths.get("six.txt"));
        traveled = new int[room.size()][room.get(0).length()];

        for(int i = 0; i < room.size(); i++){
            int index = room.get(i).indexOf("^");
            Arrays.fill(traveled[i], 1);
            if(index != -1) guard = new int[]{index, i};
        }

        while(inSquare()){
            move();
            infinite();
        }

        System.out.println(total);
    }

    private static boolean inSquare(){
        return 0 <= guard[0] && guard[0] < room.get(0).length() && 0 <= guard[1] && guard[1] < room.size();
    }

    private static void infinite(){
        int[] guardTemp = {guard[0], guard[1]};
        int directionTemp = direction;
        int[][] traveledTemp = copyArray(traveled);
        
        direction = (direction + 6) % 24;
        while(inSquare()){
            if(traveled[guard[1]][guard[0]] % direction == 0){
                total++;
                break;
            }
            move();
        }
        guard = guardTemp;
        direction = directionTemp;
        traveled = copyArray(traveledTemp);
    }

    private static void move(){
        traveled[guard[1]][guard[0]] *= direction;
        switch(direction){
            case(5) -> {
                guard[1]--;
                blocked = isBlocked();
                if(blocked) guard[1]++;
            }
            case(11) -> {
                guard[0]++;
                blocked = isBlocked();
                if(blocked) guard[0]--;
            }
            case(17) -> {
                guard[1]++;
                blocked = isBlocked();
                if(blocked) guard[1]--;
            }
            case(23) -> {
                guard[0]--;
                blocked = isBlocked();
                if(blocked) guard[0]++; 
            }
        }
        if(blocked) direction = (direction + 6) % 24;
    }

    private static int[][] copyArray(int[][] from){
        int[][] to = new int[from.length][from[0].length];
        for(int i = 0; i < from.length; i++) {
            for(int j = 0; j < from[i].length; j++){
                to[i][j] = from[i][j];
            }
        }
        return to;
    }

    private static boolean isBlocked(){
        if(!inSquare()) return false;
        return room.get(guard[1]).charAt(guard[0]) == '#';
    }
}
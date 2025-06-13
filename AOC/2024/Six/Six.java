import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Six {
    private static List<String> room;
    private static int[][] traveled;
    private static int[] guard = {-1, -1};
    private static int direction = 0;
    private static int total = 0;

    public static void main(String[] args) throws IOException{
        room = Files.readAllLines(Paths.get("six.txt"));
        traveled = new int[room.get(0).length()][room.size()];

        for(int i = 0; i < room.size(); i++){
            int index = room.get(i).indexOf("^");
            if(index != -1){
                guard = new int[]{index, i};
                break;
            }
        }

        boolean blocked = false;
        while(inSquare()){
            traveled[guard[0]][guard[1]]++;

            switch(direction){
                case(0) -> {
                    guard[1]--;
                    blocked = isBlocked();
                    if(blocked) guard[1]++;
                }
                case(1) -> {
                    guard[0]++;
                    blocked = isBlocked();
                    if(blocked) guard[0]--;
                }
                case(2) -> {
                    guard[1]++;
                    blocked = isBlocked();
                    if(blocked) guard[1]--;
                }
                case(3) -> {
                    guard[0]--;
                    blocked = isBlocked();
                    if(blocked) guard[0]++; 
                }
            }
            if(blocked) direction = (direction + 1) % 4;
        }
        for(int[] row : traveled){
            for(int location : row) if(location > 0) total++;
        }

        System.out.println(total);
    }

    private static boolean inSquare(){
        return 0 <= guard[0] && guard[0] < room.get(0).length() && 0 <= guard[1] && guard[1] < room.size();
    }

    private static boolean isBlocked(){
        if(!inSquare()) return false;
        return room.get(guard[1]).charAt(guard[0]) == '#';
    }
}
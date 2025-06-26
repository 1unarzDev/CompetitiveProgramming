import java.util.ArrayList;
import java.util.Arrays;
public class Eleven {
    private static ArrayList<Long> stones = new ArrayList<>(Arrays.asList(5L, 62914L, 65L, 972L, 0L, 805922L, 6521L, 1639064L));
    
    public static void main(String[] args){
        System.out.println(blink(25).size());
    }

    private static ArrayList<Long> blink(int times){
        if(times <= 0) return stones;
        for(int i = stones.size() - 1; i >= 0; i--){
            if(stones.get(i) == 0){
                stones.set(i, 1L);
                continue;
            }

            String convert = String.valueOf(stones.get(i));
            if(convert.length() % 2 == 0) {
                stones.add(i, Long.valueOf(convert.substring(0, convert.length() / 2)));
                stones.set(i + 1, Long.valueOf(convert.substring(convert.length() / 2)));
                continue;
            }

            stones.set(i, stones.get(i) * 2024);
        }
        return blink(times - 1);
    }
}
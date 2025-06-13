import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Nine {
    public static void main(String[] args) throws IOException{
        String input = Files.readString(Paths.get("nine.txt"));
        ArrayList<Integer> nums = new ArrayList<>();
        long sum = 0;

        for(int i = 0; i < input.length(); i++){
            if(i % 2 == 0) for(int j = 0; j < input.charAt(i) - 48; j++) nums.add(i / 2);
            else for(int j = 0; j < input.charAt(i) - 48; j++) nums.add(-1);
        }

        while(nums.indexOf(-1) != -1){
            nums.set(nums.indexOf(-1), nums.get(nums.size() - 1));
            nums.remove(nums.size() - 1);
        }

        for(int i = 0; i < nums.size(); i++) sum += (nums.get(i) * i);

        System.out.println(sum);
    }
}
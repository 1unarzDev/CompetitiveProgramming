import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class NinePt2 {
    public static void main(String[] args) throws IOException{
        String input = Files.readString(Paths.get("nine.txt"));
        ArrayList<Integer> nums = new ArrayList<>();
        ArrayList<Integer> indices = new ArrayList<>();
        long sum = 0;

        indices.add(0);
        for(int i = 0; i < input.length(); i++){
            if(i % 2 == 0) for(int j = 0; j < input.charAt(i) - 48; j++) nums.add(i / 2);
            else for(int j = 0; j < input.charAt(i) - 48; j++) nums.add(-1);
            indices.add(indices.get(i) + input.charAt(i) - 48);
        }

        for(int i = indices.size() - ((indices.size() % 2 == 0) ? 2 : 3); i >= 0; i -= 2){
            for(int j = 1; j < i; j += 2)
                if(indices.get(j + 1) - indices.get(j) > indices.get(i + 1) - indices.get(i)){
                    for(int k = 0; k < indices.get(i + 1) - indices.get(i); k++){
                        nums.set(j + k, nums.get(i + k));
                        nums.set(i + k, -1);
                    }
                }
        }

        for(int i = 0; i < nums.size(); i++) if(nums.get(i) > 0) sum += (nums.get(i) * i);

        System.out.println(sum);
    }
}
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FivePt2{
    public static void main(String[] args) throws IOException{
        List<String> ruleIn = Files.readAllLines(Paths.get("fiveRules.txt"));
        List<String> updatesIn = Files.readAllLines(Paths.get("fiveUpdates.txt"));
        Map<Integer, ArrayList<Integer>> rules = new HashMap<>();
        int count = 0;

        int before, after;
        for(String rule : ruleIn){
            before = Integer.parseInt(rule.substring(0,2));
            after = Integer.parseInt(rule.substring(3,5));
            rules.computeIfAbsent(before, k -> new ArrayList<>()).add(after);
        }

        for(String update : updatesIn){
            boolean add = false;
            int[] pages = Arrays.stream(update.split(","))
                .mapToInt(Integer::parseInt)
                .toArray();

            for(int i = 0; i < pages.length; i++){
                if(rules.containsKey(pages[i])){
                    for(int j = i - 1; j >= 0; j--){
                        if(rules.get(pages[i]).contains(pages[j])){
                            int temp = pages[j];
                            pages[j] = pages[i];
                            pages[i] = temp;
                            i = 0;
                            add = true;
                            break;
                        }
                    }
                }
            }
            if(add) count += pages[(pages.length - 1) / 2];
        }

        System.out.println(count);
    }
}
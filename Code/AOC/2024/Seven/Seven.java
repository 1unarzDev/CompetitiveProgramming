import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Seven {
    public static void main(String[] args) throws IOException{
        List<String> equations = Files.readAllLines(Paths.get("seven.txt"));
        ArrayList<Long> solutions = new ArrayList<>();
        long total = 0;

        for(String equation : equations){
            long[] parts = Arrays.stream(equation.split("[: \r\n]+"))
                .mapToLong(Long::parseLong)
                .toArray();
            solutions.add(parts[1]);

            for(int i = 2; i < parts.length; i++){
                for(int j = solutions.size() - 1; j >= 0; j--){
                    solutions.add(solutions.get(j) + parts[i]);
                    solutions.add(Long.parseLong("" + solutions.get(j) + parts[i]));
                    solutions.set(j, solutions.get(j) * parts[i]);
                }
            }
            if(solutions.contains(parts[0])) total += parts[0];
            solutions.clear();
        }
        System.out.println(total);
    }
}

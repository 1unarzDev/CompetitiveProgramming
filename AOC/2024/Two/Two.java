package Two;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Two{
    public static void main(String[] args) throws IOException{
        List<String> reports = Files.readAllLines(Paths.get("two.txt"));
        int safe = 0;

        for(String report : reports){
            int[] levels = Arrays.stream(report.split("[ \n\r]+"))
                .mapToInt(str -> Integer.parseInt(str))
                .toArray();
            
            boolean increasing = true;
            boolean decreasing = true;
            for(int i = 1; i < levels.length; i++){
                if(levels[i - 1] + 3 < levels[i] || levels[i] < levels[i - 1] + 1) increasing = false;
                if(levels[i - 1] - 1 < levels[i] || levels[i] < levels[i - 1] - 3) decreasing = false; 
            }

            if(increasing || decreasing) safe++;
        }

        System.out.println("Safe: " + safe);
    }
}
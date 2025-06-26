import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;

public class Nineteen {
    private static Set<String> want;
    private static Map<Integer, Set<String>> have;
    private static Set<Character> singles;
    private static String removeSingles;
    private static int total = 0;
    public static void main(String[] args) throws IOException {
        have = Arrays.stream(Files.readString(Paths.get("have.txt"))
                     .strip()
                     .split(", "))
                     .collect(Collectors.groupingBy(
                         String::length, 
                         TreeMap::new, 
                         Collectors.toSet()
                     ));

        singles = have.getOrDefault(1, Set.of())
                      .stream()
                      .map(str -> str.charAt(0))
                      .collect(Collectors.toSet());

        removeSingles = singles.stream()
                               .map(ch -> ch.toString())
                               .collect(Collectors.joining("", "[", "]+"));                      

        System.out.println(removeSingles);

        for(int i = 2; i <= Collections.max(have.keySet()); i++){ 
            Set<String> towels = have.getOrDefault(i, Set.of());
            Set<String> filteredTowels = towels.stream()
                                               .filter(towel -> towel.chars().anyMatch(ch -> !singles.contains((char) ch)))
                                               .collect(Collectors.toSet());
            have.put(i, filteredTowels);
        }

        want = Files.readAllLines(Paths.get("want.txt"))
                    .stream()
                    .map(String::strip)
                    .collect(Collectors.toSet());

        // for(String design : want) total += (find(design) ? 1 : 0);
        // System.out.println(total);
    }

    // private static boolean find(String design){
    //     if(design.length() == 0) return true;
    //     String problems = design.replaceAll(removeSingles, "");
    //     for(return find(design);
    // }
}

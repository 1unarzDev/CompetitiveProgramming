import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class One{
    public static void main(String[] args) throws IOException{
        /* Instantiate and Initialize */
        String content = new String(Files.readAllBytes(Paths.get("one.txt")));
        ArrayList<Integer> left = new ArrayList<>(
            Arrays.stream(content.split("[ \n\r]+"))
                  .mapToInt(Integer::parseInt)
                  .boxed()
                  .toList()
        );
        ArrayList<Integer> right = new ArrayList<>();

        for(int i = left.size() - 1; i >= 0; i -= 2){
            right.add(left.get(i));
            left.remove(i);
        }
        /* Instantiate and Initialize */

        /* Part 1 */
        int difference = 0;

        Collections.sort(left);
        Collections.sort(right);

        for(int i = 0; i < left.size(); i++) difference += Math.abs(left.get(i) - right.get(i));

        System.out.println("Difference: " + difference);
        /* Part 1 */

        /* Part 2 */
        int similarityScore = 0; 
        Map<Integer, Integer> lefts = new HashMap<>();
        Map<Integer, Integer> rights = new HashMap<>();

        countInstances(left, lefts);
        countInstances(right, rights);

        for (int key : lefts.keySet()) if(rights.containsKey(key)) similarityScore += lefts.get(key) * rights.get(key) * key; 

        System.out.println("Similarity Score: " + similarityScore);
        /* Part 2 */
    }

    private static void countInstances(List<Integer> list, Map<Integer, Integer> instances) {
        for (int i = 0; i < list.size(); i++) {
            instances.put(list.get(i), instances.getOrDefault(list.get(i), 0) + 1);
        }
    }
}
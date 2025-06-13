import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class ElevenPt2 {

    private static List<Long> input;
    private static Map<String, Long> memo = new HashMap<>();
    
    public static void main (String[] args) throws IOException {
        input = Arrays.stream(Files.readString(Paths.get("eleven.txt")).strip().split(" ")).map(Long::parseLong).toList();
        long result = calculateStones(75);
        System.out.println(result);
    }

    private static long calculateStones(int blinks) {
        long result = 0;
        for (long l : input) result += calculateStones(blinks, l);
        return result;
    }

    private static long calculateStones(long blinks, long number) {
        String key = blinks + "_" + number;

        if (memo.containsKey(key)) return memo.get(key);
        if (blinks == 0) return 1;
        if (number == 0) {
            long result = calculateStones(blinks - 1, 1);
            memo.put(key, result);
            return result;
        }
        long digits = (long) java.lang.Math.log10(number) + 1;
        if (digits % 2 == 0) {
            long divisor = (long) java.lang.Math.pow(10, digits / 2);
            long first = number / divisor;
            long second = number % divisor;
            long result = calculateStones(blinks - 1, first) + calculateStones(blinks - 1, second);
            memo.put(key, result);
            return result;
        }
        long result = calculateStones(blinks - 1, number * 2024);
        memo.put(key, result);
        return result;
    }
}
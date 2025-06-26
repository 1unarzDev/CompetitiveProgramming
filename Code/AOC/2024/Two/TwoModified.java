package Two;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TwoModified {
    public static void main(String[] args) throws IOException {
        List<String> reports = Files.readAllLines(Paths.get("two.txt"));
        int safe = 0;

        for (String report : reports) {
            int[] levels = Arrays.stream(report.split("[ \n\r]+"))
                .mapToInt(str -> Integer.parseInt(str))
                .toArray();

            if (isSafe(levels)) {
                safe++;
            } else {
                for (int i = 0; i < levels.length; i++) {
                    int[] modifiedLevels = removeLevel(levels, i);
                    if (isSafe(modifiedLevels)) {
                        safe++;
                        break;
                    }
                }
            }
        }

        System.out.println("Safe: " + safe);
    }

    private static boolean isSafe(int[] levels) {
        boolean increasing = true;
        boolean decreasing = true;
        for (int i = 1; i < levels.length; i++) {
            int diff = levels[i] - levels[i - 1];
            if (diff < 1 || diff > 3) increasing = false;
            if (diff > -1 || diff < -3) decreasing = false;
        }
        return increasing || decreasing;
    }

    private static int[] removeLevel(int[] levels, int index) {
        int[] newLevels = new int[levels.length - 1];
        for (int i = 0, j = 0; i < levels.length; i++) {
            if (i != index) {
                newLevels[j++] = levels[i];
            }
        }
        return newLevels;
    }
}
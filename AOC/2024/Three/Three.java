import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Three {
    public static void main(String[] args) throws IOException {
        String input = Files.readString(Paths.get("three.txt"));
        ArrayList<Integer> doIndices = new ArrayList<>();
        ArrayList<Integer> dontIndices = new ArrayList<>();
        int index = 0, sum = 0;

        while (index != -1) {
            index = input.indexOf("do()", index);
            if (index != -1) {
                doIndices.add(index + 3);
                index++;
            }
        }

        index = 0;
        while (index != -1) {
            index = input.indexOf("don't()", index);
            if (index != -1) {
                dontIndices.add(index);
                index++;
            }
        }

        boolean isEnabled = true;
        int doIndex = 0, dontIndex = 0;

        while (true) {
            index = input.indexOf("mul(", index);
            if (index == -1) break;

            while (doIndex < doIndices.size() && doIndices.get(doIndex) < index) {
                isEnabled = true;
                doIndex++;
            }
            while (dontIndex < dontIndices.size() && dontIndices.get(dontIndex) < index) {
                isEnabled = false;
                dontIndex++;
            }

            if (isEnabled) {
                int end = index + 4;
                for (int i = 3; i >= 0; i--) {
                    if (isNumeric(input.substring(end, end + i)) && input.charAt(end + i) == ',') {
                        int second = end + i + 1;
                        for (int j = 3; j >= 0; j--) {
                            if (isNumeric(input.substring(second, second + j)) && input.charAt(second + j) == ')') {
                                sum += Integer.parseInt(input.substring(end, end + i)) * Integer.parseInt(input.substring(second, second + j));
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            index++;
        }
        System.out.println(sum);
    }

    public static boolean isNumeric(String str) {
        return str.matches("-?\\d+(\\.\\d+)?");
    }
}
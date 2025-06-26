import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class FourPartTwo {
    public static void main(String[] args) throws IOException {
        List<String> crossword = Files.readAllLines(Paths.get("four.txt"));
        ArrayList<String> diagonals = new ArrayList<>();
        Map<DiagonalKey, int[]> diagonalIndexRemap = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        int[][] heatMap = new int[crossword.size()][crossword.size()];
        int count = 0;

        for (int i = 0; i < heatMap.length; i++) {
            for (int j = 0; j < heatMap[0].length; j++) {
                heatMap[i][j] = 0;
            }
        }

        for (int i = 0; i < crossword.size(); i++) {
            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++) {
                if (i + j + 1 < crossword.size() && j < crossword.get(i).length()) {
                    DiagonalKey key = new DiagonalKey(diagonals.size(), sb.length());
                    int[] entry = {i + j + 1, j};
                    diagonalIndexRemap.put(key, entry);
                    sb.append(crossword.get(i + j + 1).charAt(j));
                }
            }
            diagonals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++) {
                if (i + j < crossword.size() && j < crossword.get(i).length()) {
                    DiagonalKey key = new DiagonalKey(diagonals.size(), sb.length());
                    int[] entry = {j, i + j};
                    diagonalIndexRemap.put(key, entry);
                    sb.append(crossword.get(j).charAt(i + j));
                }
            }
            diagonals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++) {
                if (i - j >= 0) {
                    DiagonalKey key = new DiagonalKey(diagonals.size(), sb.length());
                    int[] entry = {j, i - j};
                    diagonalIndexRemap.put(key, entry);
                    sb.append(crossword.get(j).charAt(i - j));
                }
            }
            diagonals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++) {
                if (crossword.size() - i + j < crossword.size()) {
                    DiagonalKey key = new DiagonalKey(diagonals.size(), sb.length());
                    int[] entry = {crossword.size() - 1 - j, crossword.size() - i + j};
                    diagonalIndexRemap.put(key, entry);
                    sb.append(crossword.get(crossword.size() - 1 - j).charAt(crossword.size() - i + j));
                }
            }
            diagonals.add(sb.toString());
        }

        for (int i = 0; i < diagonals.size(); i++) {
            for (int j = 0; j < diagonals.get(i).length() - 2; j++) {
                DiagonalKey key = new DiagonalKey(i, j + 1);

                if (diagonals.get(i).charAt(j) == 'M' &&
                    diagonals.get(i).charAt(j + 1) == 'A' &&
                    diagonals.get(i).charAt(j + 2) == 'S') {
                    heatMap[diagonalIndexRemap.get(key)[0]][diagonalIndexRemap.get(key)[1]]++;
                } else if (diagonals.get(i).charAt(j) == 'S' &&
                           diagonals.get(i).charAt(j + 1) == 'A' &&
                           diagonals.get(i).charAt(j + 2) == 'M') {
                    heatMap[diagonalIndexRemap.get(key)[0]][diagonalIndexRemap.get(key)[1]]++;
                }
            }
        }

        for (int[] row : heatMap) {
            for (int cell : row) {
                if (cell == 2) count++;
            }
        }

        System.out.println(count);
    }

    static class DiagonalKey {
        int diagonalIndex;
        int charIndex;

        DiagonalKey(int diagonalIndex, int charIndex) {
            this.diagonalIndex = diagonalIndex;
            this.charIndex = charIndex;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            DiagonalKey that = (DiagonalKey) o;
            return diagonalIndex == that.diagonalIndex && charIndex == that.charIndex;
        }

        @Override
        public int hashCode() {
            return Objects.hash(diagonalIndex, charIndex);
        }
    }
}
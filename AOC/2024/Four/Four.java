import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Four {
    public static void main(String[] args) throws IOException{
        List<String> crossword = Files.readAllLines(Paths.get("four.txt"));
        ArrayList<String> diagonals = new ArrayList<>();
        ArrayList<String> verticals = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        int count = 0;

        for(int i = 0; i < crossword.size(); i++){ 
            // find xmas going forward
            count += search(crossword.get(i), "XMAS");

            // find xmas going backward
            count += search(crossword.get(i), "SAMX");

            sb.setLength(0);
            for(int j = 0; j < crossword.size(); j++){
                sb.append(crossword.get(j).charAt(i));
            }
            verticals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++){
                if (i + j + 1 < crossword.size() && j < crossword.get(i).length()){
                    sb.append(crossword.get(i + j + 1).charAt(j));
                }
            }
            diagonals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++){
                if (i + j < crossword.size() && j < crossword.get(i).length()){
                    sb.append(crossword.get(j).charAt(i + j));
                }
            }
            diagonals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++){
                if (i - j >= 0){
                    sb.append(crossword.get(j).charAt(i - j));
                }
            }
            diagonals.add(sb.toString());

            sb.setLength(0);
            for (int j = 0; j < crossword.size(); j++){
                if (crossword.size() - i + j < crossword.size()){
                    sb.append(crossword.get(crossword.size() - 1 - j).charAt(crossword.size() - i + j));
                }
            }
            diagonals.add(sb.toString());
        }

        for(String diagonal : diagonals){
            count += search(diagonal, "XMAS");
            count += search(diagonal, "SAMX");
        }

        for(String vertical : verticals){
            count += search(vertical, "XMAS");
            count += search(vertical, "SAMX");
        }

        System.out.println(count);
    }

    private static int search(String have, String want){
        return have.split(want, -1).length-1;
    }
}

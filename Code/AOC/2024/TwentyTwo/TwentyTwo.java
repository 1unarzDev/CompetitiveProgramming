import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TwentyTwo {
    public static void main(String[] args) throws IOException {
        List<Long> input = Files.readAllLines(Paths.get("twentyTwo.txt"))
                                  .stream()
                                  .map(Long::parseLong)
                                  .toList();
        long total = 0;
        for(long secret : input) total += newSecret(secret, 2000);
        System.out.println(total);
    }

    private static long newSecret(long secret, int times){
        for(int i = 0; i < times; i++){
            secret = ((secret * 64) ^ secret) % 16777216;
            secret = ((secret / 32) ^ secret) % 16777216;
            secret = ((secret * 2048) ^ secret) % 16777216;
        }
        return secret;
    }
}

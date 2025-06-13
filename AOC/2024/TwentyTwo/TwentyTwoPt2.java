import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TwentyTwoPt2 {
    public static void main(String[] args) throws IOException {
        List<Long> input = Files.readAllLines(Paths.get("twentyTwo.txt"))
                                  .stream()
                                  .map(Long::parseLong)
                                  .toList();
        ArrayList<Map<Sequence, Long>> sequencesOut = new ArrayList<>();
        Map<Sequence, Long> outs = new HashMap<>();
        for(long secret : input) sequencesOut.add(newSecret(secret, 2000));
        for(Map<Sequence, Long> sequenceOut : sequencesOut){
            for(Sequence sequence : sequenceOut.keySet()){
                if(outs.containsKey(sequence)) outs.put(sequence, sequenceOut.get(sequence) + outs.get(sequence));
                else outs.put(sequence, sequenceOut.get(sequence));
            }
        }
        System.out.println(Collections.max(outs.keySet().stream().map(sequence -> outs.get(sequence)).toList()));
    }

    private static Map<Sequence, Long> newSecret(long secret, int times){
        Map<Sequence, Long> possibilities = new HashMap<>();
        Sequence sequence = new Sequence(new long[4]);
        for(int i = 0; i < 4; i++){
            long prev = secret % 10;
            secret = operation(secret);
            sequence.changes[i] = secret % 10 - prev;
        }
        possibilities.put(sequence, secret % 10);
        for(int i = 4; i < times; i++){
            long prev = secret % 10;
            secret = operation(secret);
            sequence.shift(secret % 10 - prev);
            if(!possibilities.containsKey(sequence)) possibilities.put(sequence.copy(), secret % 10);
        }
        return possibilities;
    }

    private static long operation(long in){
        in = ((in * 64) ^ in) % 16777216;
        in = ((in / 32) ^ in) % 16777216;
        return ((in * 2048) ^ in) % 16777216;
    }

    private static class Sequence {
        long[] changes;

        Sequence(long[] changes){
            this.changes = changes;
        }

        public void shift(long newVal) {
            System.arraycopy(changes, 1, changes, 0, changes.length - 1);
            changes[changes.length - 1] = newVal;
        }

        public Sequence copy(){
            return new Sequence(Arrays.copyOf(changes, changes.length));
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Sequence other = (Sequence) o;
            return Arrays.equals(this.changes, other.changes);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(changes);
        }
    }
}
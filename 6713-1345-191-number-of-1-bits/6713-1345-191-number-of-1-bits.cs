public class Solution {
    public int HammingWeight(int n) {
        int[] table = PrepareLookupTable();

        int counter = table[n & 0xff];
        n >>= 8;

        counter += table[n & 0xff];
        n >>= 8;

        counter += table[n & 0xff];
        n >>= 8;

        counter += table[n & 0xff];
        n >>= 8;

        return counter;
    }

    public int[] PrepareLookupTable(){
        int[] table = new int[256];
        for (int i = 1; i < 256; i++) {
            table[i] = (i & 1) + table[i / 2];
        }
        return table;
    }
}
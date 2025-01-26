public class Solution {
    public int[] CountBits(int n) {
        int[] table = PrepareLookupTable();
        int[] ans = new int[n+1];

        for(int i=0; i<=n; i++){
            int j=i;
            int counter = table[j & 0xff];
            j >>= 8;

            counter += table[j & 0xff];
            j >>= 8;

            counter += table[j & 0xff];
            j >>= 8;

            counter += table[j & 0xff];
            j >>= 8;

            ans[i] = counter;
        }
        return ans;
    }

    public int[] PrepareLookupTable(){
        int[] table = new int[256];
        for (int i = 1; i < 256; i++) {
            table[i] = (i & 1) + table[i / 2];
        }
        return table;
    }
}
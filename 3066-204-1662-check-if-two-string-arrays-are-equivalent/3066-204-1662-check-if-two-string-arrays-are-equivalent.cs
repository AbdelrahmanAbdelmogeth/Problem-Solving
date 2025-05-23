public class Solution {
    public bool ArrayStringsAreEqual(string[] word1, string[] word2) {
        int i=0, j=0; //these two point to the string inside the word array
        int c1=0, c2=0; //these two points to the char inside each string

        while(i<word1.Length && j<word2.Length){
            if(word1[i][c1] != word2[j][c2])
                return false;

            c1++;
            if(c1==word1[i].Length){
                i++;
                c1=0;
            }

            c2++;  
            if(c2==word2[j].Length){
                j++;
                c2=0;
            }  
        }
       // Return true only if both arrays are fully traversed
        return i == word1.Length && j == word2.Length && c1 == 0 && c2 == 0;
    }
}
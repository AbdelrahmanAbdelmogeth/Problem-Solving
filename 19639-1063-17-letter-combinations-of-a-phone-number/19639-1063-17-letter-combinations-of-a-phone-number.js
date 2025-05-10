/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(digits.length <= 0)
        return [];

    phone_map = {
        "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
        "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
    }  

    const result = [];

    function backtrack(index, str){
        if(str.length == digits.length){
            result.push(str.join(''));
            return;
        }

        const letters = phone_map[digits[index]];
        for(let letter of letters){
            str.push(letter);
            backtrack(index + 1, str);
            str.pop();
        }
    }   

    backtrack(0, []);
    return result;
};


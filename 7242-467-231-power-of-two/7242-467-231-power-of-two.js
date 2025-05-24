/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    // check n > 0 and n & n-1 that will be 0 if it's power of 2
    return (n > 0) & ((n & (n - 1)) == 0);
};
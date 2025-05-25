/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    const number_occurrences_map = new Map();
    const occurrences_set = new Set();

    for(const num of arr)
        number_occurrences_map.set(num, (number_occurrences_map.get(num) || 0) + 1);

    for(const [num, occurrence] of number_occurrences_map){
        if(occurrences_set.has(occurrence))
            return false;
        occurrences_set.add(occurrence);    
    }

    return true;
};
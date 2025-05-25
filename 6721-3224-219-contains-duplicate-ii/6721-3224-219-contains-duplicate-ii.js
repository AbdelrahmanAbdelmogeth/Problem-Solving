/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    const number_index_map = new Map();

    for(let i=0; i<nums.length; i++){
        if(number_index_map.has(nums[i])){
            const j = number_index_map.get(nums[i]);
            if(Math.abs(i-j) <= k)
                return true;
        }
        number_index_map.set(nums[i], i);
    }

    return false;
};
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    const monotonic_decreasing_stack = [];
    const next_greater_map = new Map();

    for(let i=nums2.length-1; i>=0; i--){
        while(monotonic_decreasing_stack.length > 0 && monotonic_decreasing_stack[monotonic_decreasing_stack.length - 1] <= nums2[i])
            monotonic_decreasing_stack.pop();

        if(monotonic_decreasing_stack.length == 0)
            next_greater_map.set(nums2[i], -1);
        else
            next_greater_map.set(nums2[i], monotonic_decreasing_stack[monotonic_decreasing_stack.length - 1]);

        monotonic_decreasing_stack.push(nums2[i]);
    }

    return nums1.map(num => next_greater_map.get(num));
};
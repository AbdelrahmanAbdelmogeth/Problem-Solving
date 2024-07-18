function twoSum(nums: number[], target: number): number[] {
    const num_index = new Map<number, number>();
    const ans :number[] = [0,0];
    
    for(let i=0; i<nums.length; i++){
        if(num_index.has(target - nums[i])){
            ans[0] = num_index.get(target - nums[i]);
            ans[1] = i;
            break;
        }
        num_index.set(nums[i], i);  
        
    }
    return ans;
};
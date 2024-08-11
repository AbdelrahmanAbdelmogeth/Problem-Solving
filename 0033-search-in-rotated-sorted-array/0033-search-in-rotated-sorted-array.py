class Solution(object):
    def search(self, List, target):
        low = 0; high = len(List) - 1 
        while low <= high:
            mid = low + (high - low) // 2
            if List[mid] == target: 
                return mid
            #-------------------------------------------
            if List[low] <= List[mid]: #this means the left side is sorted [10,25,30,0,1,3] and the rotation on the right
                if target >= List[low] and target < List[mid]: #indeed target on the left
                    high = mid - 1
                else:
                    low = mid + 1  
            else: #this means the right half is sorted [4,0,1,2,3] and the rotation on the left
                if target > List[mid] and target <= List[high]:
                    low = mid + 1
                else:
                    high = mid - 1
                    
        return -1 #means there is no such element in the array        
        
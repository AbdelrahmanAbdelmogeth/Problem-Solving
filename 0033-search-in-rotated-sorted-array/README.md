<h2><a href="https://leetcode.com/problems/search-in-rotated-sorted-array/">33. Search in Rotated Sorted Array</a></h2><h3>Medium</h3><hr><div><p>There is an integer array <code>nums</code> sorted in ascending order (with <strong>distinct</strong> values).</p>

<p>Prior to being passed to your function, <code>nums</code> is <strong>possibly rotated</strong> at an unknown pivot index <code>k</code> (<code>1 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,5,6,7]</code> might be rotated at pivot index <code>3</code> and become <code>[4,5,6,7,0,1,2]</code>.</p>

<p>Given the array <code>nums</code> <strong>after</strong> the possible rotation and an integer <code>target</code>, return <em>the index of </em><code>target</code><em> if it is in </em><code>nums</code><em>, or </em><code>-1</code><em> if it is not in </em><code>nums</code>.</p>

<p>You must write an algorithm with <code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
<strong>Output:</strong> 4
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
<strong>Output:</strong> -1
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1], target = 0
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>All values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is an ascending array that is possibly rotated.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>
</div>
Solution

### Naive Solution O(n) :

Linear Search: Loop through the array from index 0 to the end and compare each element with the target element if a match return the current index (first occurrence) if not continue and return -1 at the end which means no target found in the array.

### Fast Solution [Binary Search] O(n log n):

1. Start with a normal binary search
  
  ```
  low = 0, high = len(arr) - 1
  mid = low + (high - low) / 2
  ```
  
2. We need to decide which half of the array is sorted. which one to skip and which one to search for.
  An Original array would be : [0,1,2,3,4,5,6] 
  The Rotated array : [3,4,5,6,0,1,2] or [4,5,6,0,1,2,3]
  
  1. The left half is sorted
    
    We can achieve that by comparing the middle element with the one at low index :
    
    ```
    if(arr[low] <= arr[mid])
    ```
    
    this means the array is like this [3,4,5,6,0,1,2] or maybe there is a case where it's repeated like this [3,3,3,3,0,1,2] (corner case)
    
    In this case, we have two cases to consider when update our low or high indices
    
    - if the target is greater or equal to the arr[low] and it's smaller than arr[mid]
      
      in this case we update the high index to be ``high = mid - 1`` that means our target in the left for sure
      
    - else our target is on the right and we need to update the low index to be ``low = mid + 1``
      
  2. The other Alternative the right half is sorted
    
    this means the array is like this [3,0,1,2]
    
    In this case, we have two cases to consider to update our low or high indices
    
    - if the target is greater than arr[mid] and it's smaller than or equal arr[mid]
      
      in this case we update the high index to be `low = mid + 1` which means our target on the right for sure
      
    - else our target is on the left and we need to update low index to be `high = mid - 1`
      
  3. when to stop as usual binary search we stop when ``low > high``
    
  4. When no element is found by comparing each ``arr[mid] == target`` we return -1 or return mid if a target has been found.

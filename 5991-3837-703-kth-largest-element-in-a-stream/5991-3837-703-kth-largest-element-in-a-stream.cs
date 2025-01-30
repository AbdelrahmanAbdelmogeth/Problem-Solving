public class KthLargest {
    int k; // to store the kth Largest
    private PriorityQueue<int, int> minHeap; // mentain a min heap to always mentain the lowest value
    
    public KthLargest(int k, int[] nums) {
        minHeap = new PriorityQueue<int, int>(); // initialize the min heap
        this.k = k; // initialize the kth largest to keep track of it

        foreach (var num in nums) // construct the min heap
            Add(num);
    }
    
    public int Add(int val) {
        minHeap.Enqueue(val, val); // enqueue the value with priority val (if we want max heap we use -ve in priority)
        if(minHeap.Count > this.k) // if the number of elements in the queue excceeds the k we remove one that's make sure we mentain only the kth largest in the peek of the queue
            minHeap.Dequeue();
        return  minHeap.Peek(); // always there is the kth largest (the lowest value) in the peek of the queue     
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.Add(val);
 */
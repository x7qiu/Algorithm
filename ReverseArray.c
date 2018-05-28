// Runtime: O(n)
// Memory:  O(1)

void Reverse(int* nums, int low, int high){
    while (low <= high){
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
        low++;
        high--;
    }
}



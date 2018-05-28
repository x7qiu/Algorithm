int BinarySearch(int* nums, int low, int high, int key){
    while (low <= high){
        int mid = low + (high - low)/2;

        if (nums[mid] == key)
            return mid;
        if (nums[mid] < key)
            high = mid - 1;
        if (nums[mid] > key)
            low = mid + 1;
    }

    printf("not found\n");
    return -1;
}


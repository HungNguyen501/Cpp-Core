namespace mrroot501 {

template<typename T>
void mergeHalfs(T arr[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) {return;}
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int left = leftStart, right = rightStart;
    T temp[rightEnd - leftStart + 1];
    int index = 0;
    while (left <= leftEnd && right <= rightEnd)
    {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        }
        else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }
    while (left <= leftEnd)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }
    while (right <= rightEnd)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }
    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i - leftStart];
    }
}

template<typename T>
void mergeSort(T arr[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    mergeSort(arr, leftStart, middle);
    mergeSort(arr, middle + 1, rightEnd);
    mergeHalfs(arr, leftStart, rightEnd);
}

template void mergeSort(int arr[], int leftStart, int rightEnd);
template void mergeSort(float arr[], int leftStart, int rightEnd);
template void mergeSort(long arr[], int leftStart, int rightEnd);

} // namespace mrroot501

namespace mrroot501 {

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;

    int pivot = arr[l];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if(i <= j) swap(&arr[i++], &arr[j--]);
    }

    quickSort(arr, l, j);
    quickSort(arr, i, r);
}

} // namespace mrroot501

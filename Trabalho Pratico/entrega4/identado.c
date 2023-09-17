struct Element {
    int value;
    int frequency;
};

void swap(struct Element* a, struct Element* b) {
    struct Element temp = *a;
    *a = *b;
    *b = temp;
}
int partition(struct Element arr[], int low, int high) {
    int pivot = arr[high].frequency;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].frequency >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    struct Element* elements = (struct Element*)malloc(numsSize * sizeof(struct Element));
    for (int i = 0; i < numsSize; i++) {
        elements[i].value = nums[i];
        elements[i].frequency = 0;
    }

    int uniqueCount = 0;
    for (int i = 0; i < numsSize; i++) {
        int foundIndex = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (elements[j].value == nums[i]) {
                foundIndex = j;
                break;
            }
        }
        if (foundIndex != -1) {
            elements[foundIndex].frequency++;
        } else {
            elements[uniqueCount].value = nums[i];
            elements[uniqueCount].frequency = 1;
            uniqueCount++;
        }
    }
    quickSort(elements, 0, uniqueCount - 1);

    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = elements[i].value;
    }

    *returnSize = k;
    free(elements);

    return result;
}
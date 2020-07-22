int minArray(int* numbers, int numbersSize){
    int left = 0, right = numbersSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (numbers[mid] < numbers[right]) {
            right = mid;
        } else if (numbers[mid] > numbers[right]) {
            left = mid + 1;
        } else {
            --right;
        }
    }
    return numbers[left];
}

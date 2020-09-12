#define INT_MAX 2147483647
#define INT_MIN -2147483648

double average(int* salary, int salarySize){
    int sum = 0, max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < salarySize; ++i) {
        sum += salary[i];
        if (min > salary[i]) min = salary[i];
        if (max < salary[i]) max = salary[i];
    }
    return (double)(sum - min - max) / (salarySize - 2);
}

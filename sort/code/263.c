// bool isUgly(int num){
//     if (num <= 0) return false;
//     if (num == 1) return true;
//     return isUgly (num % 2 == 0? num / 2: num % 3 == 0? num / 3: num % 5 == 0? num / 5: 0);
// }

bool isUgly(int num){
    if (num <= 0) return false;
    while (num != 1 && num != 0) {
        num = num % 2 == 0? num / 2: num % 3 == 0? num / 3: num % 5 == 0? num / 5: 0;
    }
    return num;
}

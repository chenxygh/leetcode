// iteration
// int addDigits(int num){
//     int sum  = num;
//     while (sum >= 10) {
//         num = sum;
//         sum = 0;
//         while (num) {
//             sum += num % 10;
//             num /= 10;
//         }
//     }
//     return sum;
// }

// recursion
// int addDigits(int num){
//     if (num < 10) return num;
//     int sum = 0;
//     while (num) {
//         sum += num % 10;
//         num /= 10;
//     }
//     return addDigits(sum);
// }

// mathematical
int addDigits(int num){
    // return num < 10? num: num % 9? num % 9: 9;
    return (num - 1) % 9 + 1;
}

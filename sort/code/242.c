#include <stdio.h>
#include <string.h>

// method 1: 简单逐一比较， T: O(N2) S: O(1)
// bool isAnagram(char * s, char * t){
//     int length = strlen(t);
//     for ( ; s[0] != '\0' && length > 0; ++s) {
//         for (int i = 0; i < length; ++i) {
//             if (t[i] == s[0]) {// find counterpart
//                 char temp = t[length - 1];
//                 t[--length] = t[i];
//                 t[i] = temp;
//                 break;
//             }
//         }
//     }

//     return s[0] == '\0' && length == 0;
// }

// method 2: 先排序，用 NLOGN 的，如，heap， T: O(NLOGN) S: O(1)
// void adjustDown (char *a, int k, int n) {
//     char temp = a[k - 1];
//     for (int i = k * 2; i <= n; i = k * 2) {
//         if (i + 1 <= n && a[i + 1 - 1] > a[i - 1]) ++i;
//         if (temp >= a[i - 1]) break;
//         a[k - 1] = a[i - 1];
//         k = i;
//     }
//     a[k - 1] = temp;
// }

// void buildHeap (char *a, int n) {
//     for (int i = n / 2; i >= 1; --i) {
//         adjustDown(a, i, n);
//     }
// }

// void heapSort (char *a, int n) {
//     buildHeap (a, n);
//     for (int i = n - 1; i >= 1; --i) {
//         char temp = a[0];
//         a[0] = a[i];
//         a[i] = temp;
//         adjustDown(a, 1, i);
//     }
// }

// bool isAnagram(char * s, char * t){
//     int n = strlen(s);
//     int m = strlen(t);
//     if (n != m) return false;

//     heapSort(s, n);
//     heapSort(t, n);
//     while (s[0] != '\0') {
//         if (s[0] != t[0]) return false;
//         s++;
//         t++;
//     }
//     return true;
// }

// method 3: 计数器法（哈希函数，key == addr，简易哈希表）
// 对于 unicode, 数据范围很大的数据时，
bool isAnagram(char * s, char * t){
    int n = strlen(s);
    int m = strlen(t);
    if (n != m) return false;
    
    char hashList[26] = {0};
    for (int i = 0; i < n; ++i) hashList[s[i] - 'a']++;
    for (int i = 0; i < n; ++i) hashList[t[i] - 'a']--;
    for (int i = 0; i < 26; ++i) if (hashList[i] != 0) return false;

    return true;
}

int main(int argc, char const *argv[])
{
	char s[20] = "hello world";
	char t[20] = "worldhello ";
	int f = isAnagram(s, t);
	printf("%s\n", s);
	printf("%s\n", t);
	printf("%d\n", f);
	return 0;
}

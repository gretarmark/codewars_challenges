
#include <stdio.h>
#include <stdlib.h> 
#include <stddef.h>


int stray(size_t n, int arr[n]);
int stray2(size_t n, int arr[n]);
int stray3(size_t n, int arr[n]);
int stray4(size_t n, int arr[n]);

int main()
{
    int example[5] = { 1, 1, 2, 1, 1 };

    stray(5, example);

    return 0;
}



// My solution:
int stray(size_t n, int arr[n]) {
    int val;
    int len = n - 1;

    if (arr[0] != arr[1] && arr[0] != arr[2]) {
        val = arr[0];
        return val;
    }

    if (arr[len] != arr[len - 1] && arr[len] != arr[len - 2]) {
        val = arr[len];
        return val;
    }

    for (int i = 1; i < len; i++) {
        if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) {
            val = arr[i];
            return arr[i];
        }
    }

}

//Solutions from others
int stray2(size_t n, int arr[n]) {
    int i, num1;
    num1 = arr[0];
    if (num1 != arr[1] && num1 != arr[2]) return num1;
    for (i = 1; i < n; i++) {
        if (num1 != arr[i]) {
            return arr[i];
        }
    }
}

int stray3(size_t n, int arr[n]) {
    int res = 0;
    for (size_t i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int stray4(size_t n, int arr[n]) {
    int x = 0;
    while (n--) x ^= *arr++;
    return x;
}
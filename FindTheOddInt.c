
/*
Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/

#include <stddef.h>

int find_odd (size_t length, const int array[length])
{
  int var = 0;
  
  for(size_t i=0; i<length; i++){
    
    var ^= array[i];
  }
  
    return var;
}


/* SAMPLE TEST

#include <stdio.h>
#include <criterion/criterion.h>

extern int find_odd (size_t length, const int array[length]);

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

#define fixed_test(expected, array) do_test(ARR_LEN(array), array, expected)

static void do_test (size_t length, const int array[length], int expected);

Test(tests_suite, sample_tests)
{
	fixed_test(5, ((int[])
		{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}
	));
	fixed_test(-1, ((int[])
		{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}
	));
	fixed_test(5, ((int[])
		{20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5}
	));
	fixed_test(10, ((int[])
		{10}
	));
	fixed_test(10, ((int[])
		{1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1}
	));
	fixed_test(1, ((int[])
		{5, 4, 3, 2, 1, 5, 4, 3, 2, 10, 10}
	));
}

static void print_array (size_t length, const int array[length])
{
    printf("{");
    for (size_t i = 0; i < length; i++)
        printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
    printf("}");
}

static void do_test (size_t length, const int array[length], int expected)
{
    int actual = find_odd(length, array);
    if (actual != expected) {
        printf("for array = ");
        print_array(length, array);
        fflush(stdout);
    }
    cr_assert_eq(actual, expected,
        "expected %d but got %d",
        expected, actual
    );
}


*/

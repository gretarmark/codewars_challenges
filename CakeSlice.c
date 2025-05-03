
/*
Task
A cake is sliced with n straight lines. Your task is to calculate the maximum number of pieces the cake can have.

Example
For n = 0, the output should be 1.

For n = 1, the output should be 2.

For n = 2, the output should be 4.

For n = 3, the output should be 7.

See the following image to understand it:
*/

//My solution:
int slicecake(int n)
{
    return n * (n + 1) / 2 + 1;
}

//other solutions
int slicecake(int n) {
  return n > 0 ? slicecake(n-1)+n: 1;
}


int slicecake(int n)
{
  int count = 1;
  for (int i = 0; i <= n; ++i)
    count += i;
  return count;
}

int slicecake(int n) {
  //prove to me that cake is not a lie!
  int num = 1;
  for(int i = 0; i <= n; i++) {
    num += i;
  }
  return num;
}

int slicecake(int n) {
  //prove to me that cake is not a lie!
  return !n ? 1 : n * 2 + ( slicecake( n-1)-n);
}

int slicecake(int n) {
  if(n==0)return 1;
  return slicecake(n-1)+n;
}

slicecake(n){return 1+n*++n/2;}


/* SAMPLE TEST
#include <criterion/criterion.h>

int slicecake(int n);

void test_slicecake(int n, int exp) {
    int res = slicecake(n);
    cr_expect_eq(res, exp, "For: n = %d expected %d. Instead got: %d", n, exp, res);
}

Test(BasicTest, should_pass_all_the_tests_provided) {
    test_slicecake(0, 1);
    test_slicecake(1, 2);
    test_slicecake(2, 4);
    test_slicecake(3, 7);
    test_slicecake(10, 56);
}
*/


/*
Description:
Count the number of exclamation marks and question marks, return the product.

Examples
""          --->   0
"!"         --->   0
"!ab? ?"    --->   2
"!!"        --->   0
"!??"       --->   2
"!???"      --->   3
"!!!??"     --->   6
"!!!???"    --->   9
"!???!!"    --->   9
"!????!!!?" --->  20
*/

//My solution
unsigned product (const char *string)
{
  
  char ExMark = 0x21;
  char QMark  = 0x3F;
  int counterEx = 0;
  int counterQ = 0;
  int i = 0;

  while (string[i] != '\0') {
    if(string[i] == ExMark) counterEx++;
    else if(string[i] == QMark) counterQ++;
    i++;
  }
  return counterEx * counterQ;
}

//Other solutions
unsigned product (const char *string)
{
  int e = 0, q = 0;
  while(*string){
    e += (*string == '!');
    q += (*string == '?');
    string++;
  }
  return e * q;
}

//Other solution
#include <string.h>

unsigned product(const char* string)
{
    unsigned excl = 0;
    unsigned ques = 0;
    for (size_t i = 0, len = strlen(string); i < len; ++i)
    {
        switch (string[i])
        {
            case '!':
                ++excl;
                break;
            case '?':
                ++ques;
                break;
            default:
                continue;
        }
    }
    return excl * ques;
}

//Other solution
unsigned product (const char *s)
{
  unsigned x = 0, q = 0;
  
  for (; *s; s++) x += *s == '!', q += *s == '?';
  
  return x * q;
}


/* SAMPLE TEST
#include <criterion/criterion.h>

static void do_test (const char *string, unsigned expected);

Test(tests_suite, sample_tests)
{
// I hate trigraphs ...
  do_test("", 0);
  do_test("!", 0);
  do_test("!ab\? \?", 2);
  do_test("!!", 0);
  do_test("!\?\?", 2);
  do_test("!\?\?\?", 3);
  do_test("!!!\?\?", 6);
  do_test("!!!\?\?\?", 9);
  do_test("!\?\?\?!!", 9);
  do_test("!\?\?\?\?!!!\?", 20);
}

extern unsigned product (const char *string);

static void do_test (const char *string, unsigned expected)
{
  unsigned actual = product(string);
  cr_assert_eq(actual, expected,
    "expected %u but got %u for string:\n\"%s\"\n",
    expected, actual, string
  );
}
*/


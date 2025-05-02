/*
Given the node object:

Node:
  val: <int>,
  left: <Node> or null,
  right: <Node> or null
write a function compare(a, b) which compares the two trees defined by Nodes a and b and returns true if they are equal in structure and in value and false otherwise.

Examples:

1       1
| \     | \
2  3    2  3
=> true

1       1
| \     | \
3  3    2  3
=> false (values not the same 2 != 3)

1       1
| \     |
2  3    2
        |
        3
=> false (structure not the same)
  */



// Solution 1:

#include <stdbool.h>
#include <stddef.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

bool equal_trees (const TreeNode *a, const TreeNode *b)
{
    if(a == NULL && b == NULL)
      return true;
    if(a == NULL || b == NULL)
      return false;
    else if (a->val != b->val) 
      return false;
  
    return equal_trees(a->left, b->left) && equal_trees(a->right, b->right);
}


//Best solution:
bool equal_trees (const TreeNode *a, const TreeNode *b)
{
    return (!a && !b) || (a && b && a->val == b->val &&
            equal_trees(a->left, b->left) && equal_trees(a->right, b->right));
}


//Another solution:
bool equal_trees (const TreeNode *a, const TreeNode *b)
{
    if (!!a ^ !!b) return false;
    if (!a) return true;
    if (a->val != b->val) return false;
    return equal_trees(a->left, b->left) && equal_trees(a->right, b->right);
}


/*SAMPLE TEST

#include <criterion/criterion.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

extern void do_test (const TreeNode *a, const TreeNode *b, bool expected);

Test(tests_suite, sample_tests)
{
	TreeNode a = {1, NULL, NULL};
	TreeNode b = {1, NULL, NULL};
	TreeNode c = {2, NULL, NULL};

    do_test(&a, &b, true);
    do_test(&b, &a, true);
    do_test(&a, &c, false);
    do_test(NULL, NULL, true);
    do_test(&a, NULL, false);
    do_test(NULL, &c, false);
}

*/

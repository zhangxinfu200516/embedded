#include <iostream>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left_next;
	TreeLinkNode *right_next;
	TreeLinkNode(int _val) : val(_val),left_next(NULL),right_next(NULL) {};
};	
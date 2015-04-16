// CMPE 180-92 PE3 SPRING 2014

#define	LENGTH	8
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
	cout << "testSumOfKeys by YourFirstName" << endl;

	bSearchTreeType<int>  tree;

	int i, input[LENGTH] = {11, 7, 10, 8, 6, 5, 9, 13};

	for (i = 0; i < LENGTH; ++i) tree.insert(input[i]);

	cout << endl << "Tree nodes in inorder: ";
	tree.inorderTraversal();
	cout << endl;

	cout << "sum of keys of all nodes = " << tree.sumOfKeys(ALL_LEVEL) << endl;
	cout << "sum of keys of odd-level nodes = " << tree.sumOfKeys(ODD_LEVEL) << endl;
	cout << "sum of keys of even-level nodes = " << tree.sumOfKeys(EVEN_LEVEL) << endl;

	cout << endl << "***over***" << endl;

	return 0;
}

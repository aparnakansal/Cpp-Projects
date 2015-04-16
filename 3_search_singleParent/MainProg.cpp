
//70 50 100 30 60 80 110 20 68 90 120 25 62 -999

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
	bSearchTreeType<int>  treeRoot, otherTreeRoot;

	int num;

	cout << "Enter numbers ending with -999" << endl;
	cin >> num;

	while (num != -999)
	{
		treeRoot.insert(num);
		cin >> num;
	}

	cout << endl << "Tree nodes in inorder: ";
	treeRoot.inorderTraversal();
	cout << endl;

	cout << "Tree Height: " << treeRoot.treeHeight()
		 << endl;
	cout << "Number of single Parents: "
		 << treeRoot.singleParent() << endl;

	cout << endl;

	return 0;
}

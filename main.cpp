#include <iostream>
#include <ctime>
#include <cstdlib>
#include "tree.h"
using namespace std;

template<class T>
void Delete(Tree<T> &mytree_balanced, int num) {
	for (int i = 0; i < num; i++)
	{
		int randn =(rand()% 100 - 1) + 1;
		Node<T>* p = Searching(mytree_balanced, randn);
		if(p->key == randn && !mytree_balanced.isEmpty()) {
		mytree_balanced.deleteNode(p);
		}
	}
}

template<class T>
Node<T>* Searching(Tree<T> &mytree_balanced, int num) {
	Node<T>*p = mytree_balanced.searching(num);
	if (p->key == num) {
		cout << num << " is in my tree." << endl;
		return p;
	}
	else {
		cout << num << " is not in my tree." << endl;

	}
}

template<class T>
void insert(Tree<T> &mytree_int, int num) {
	mytree_int.clear();
	for (int i = 0; i < num; i++)
	{
		int temp = (rand()% 100 - 1)  + 1;
		mytree_int.insert(temp);
		cout << temp << " ";
	}
}

template<class T>
void Balancing(Tree<T> &mytree_int,Tree<T> &mytree_balanced, int num) {
	mytree_balanced.clear();
	mytree_int.inorder(); //insert to array
	mytree_balanced.balance(mytree_int.data, 0, num-1);
}

void main()
{
	Tree<int> mytree_int, mytree_balanced,mytree_balanced2;
	int menu = 0,numinsert = 0,numdel = 0,numsearch=0;
	srand(time(NULL));
	while (menu != -1) {
		cout << endl;
		cout << "Enter 1: Insert a number into tree." << endl;
		cout << "Enter 2: Search a number into tree." << endl;
		cout << "Enter 3: Delete a number into tree." << endl;
		cout << "Enter 4: Print a number into tree." << endl;
		cin >> menu;
		switch (menu){
		case 1: {
					cout << endl;
					cout << "How many a number which you want to insert :";
					cin >> numinsert;
					mytree_int.data = NULL;
					mytree_int.data = new int[numinsert];
					cout << endl;
					insert(mytree_int, numinsert);
					cout << endl;
					cout << "The height of tree(Before balance) :" << mytree_int.get_height();
					cout << endl;
					mytree_int.inorder(); //insert to array
					cout << endl;
					Balancing(mytree_int, mytree_balanced, numinsert);
					mytree_balanced.print();
					cout << endl;
					cout << "The new height of tree(After balancing) :" << mytree_balanced.get_height();
					cout << endl;
					cout << "--------------------------------------------------------" <<endl;
					break;
		}
		case 2: {
					cout << "What element you want to search :";
					cin >> numsearch;
					Searching(mytree_balanced, numsearch);
					cout << endl;
					cout << "--------------------------------------------------------" <<endl;
					break;
		}
		case 3: {
					cout << "How many a generate number you want to delete :";
					cin >> numdel;
					Delete(mytree_balanced, numdel);
					cout << endl;
					cout << "Now your tree has element :";
					mytree_balanced.print();
					cout << endl;
					cout << "--------------------------------------------------------" <<endl;
					break;


		}
		case 4: {
				cout << "Print :";
				mytree_balanced.print();
				cout << endl;
				cout << "--------------------------------------------------------" <<endl;
				break;

		}
		}

	}

}

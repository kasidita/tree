#include <stack>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node
{
public:
	Node() { left = right = NULL; visited = false; }
	Node(const T& el, Node *l = 0, Node *r = 0)
	{
		key = el; left = l; right = r;visited = false;
	}
	bool get_visited() { return visited;}
	void set_visited(bool v) { visited = v;}
	T key;
	Node *left, *right;
private:
	bool visited;
};

template<class T>
class Tree {
public:
	Tree() { root = 0;height = 0;count=0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0;height = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void print() { print(root); }
	void insert(const T& el);
	void deleteNode(Node<T> *& node);
	void balance(T data[], int first, int last);
	int get_height() { return height; }
	Node<T>* searching(const T &el);
	T* data;
	int count;
	Node<T> *root,*parent;
	void clear(Node<T> *p);
	void inorder(Node<T> *p);
	void print(Node<T> *p);
	void visit(Node<T> *p);
	int height;
};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {

		clear(p->left);
		clear(p->right);
		delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p) {
	//TO DO! This is for an inorder tree traversal!
	stack<Node<T>*> parents;
	while(p != NULL) { // use LVR Method.
		if(p->left != NULL && !p->left->get_visited()) {
			parents.push(p);
			p = p->left;
		}
		else if(p->right != NULL && !p->right->get_visited()) {
			if(!p->get_visited()) {
				p->set_visited(true);
				data[count] = p->key;
				count++;
			}
			parents.push(p);
			p = p->right;
		}
		else if(!parents.empty()) {
			if(!p->get_visited()) {
				p->set_visited(true);
				data[count] = p->key;
				count++;
			}
			p = parents.top();
			parents.pop();
			if(!p->get_visited()) {
				p->set_visited(true);
				data[count] = p->key;
				count++;

			}
		}else {
			p = NULL;
		}
	}
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	int hi = 0;
	while(p != 0) {
		prev = p;
		if(p->key < el){
			//cout << "go to right"<< endl;
			p=p->right;
			hi++;
		}
		else{
			//cout << "go to left" << endl;
			p=p->left;
			hi++;
		}
		if(hi > height) {
			height = hi;
		}
	}
	if(root == 0){
		//cout << "first node " << el << endl;
		root = new Node<T>(el);
	}
	else if(prev->key<el){
		//cout << "create node right "<< el  << endl;
		prev->right = new Node<T>(el);
	}
	else {
		//cout << "create node left "<< el  << endl;
		prev->left = new Node<T>(el);
	}
}

template<class T>
Node<T>* Tree<T>::searching(const T &el) {
	Node<T> *ptr = root;
	parent = ptr;
	while (ptr != NULL) {
		if (ptr->key == el) {
			return ptr;
			break;
		}
		if(parent->left == ptr) {
			parent = parent->left;
		}
		else if(parent->right == ptr){
			parent = parent->right;
		}
		if (ptr->key < el) {
			ptr = ptr->right;
		}
		else if (ptr->key > el) {
			ptr = ptr->left;
		}
	}
}


template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev,*curr = node;

	  //We're looking at a leaf node
    if( curr->left == NULL && curr->right == NULL) {
        if(parent->left == curr) {
            parent->left = NULL;
		}
        else{
            parent->right = NULL;
		}
        delete curr;
		return;
    }


    // Node with single child
    if((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)) {
        if(curr->left == NULL && curr->right != NULL) {
            if(parent->left == curr) {
                parent->left = curr->right;
            } else {
                parent->right = curr->right;
            }
        } else { // left child present, no right child
            if(parent->left == curr) {
                parent->left = curr->left;
            } else {
                parent->right = curr->left;
            }
        }
        delete curr;
        return;
    }

    // Node with 2 children
    if (node->left != NULL && node->right != NULL) {
		curr = node->left;
		prev = node;
		while (curr->right != 0) {
			prev = curr;
			curr = curr->right;
		}
		node->key = curr->key;
		if (prev == node) {
			prev->left = curr->left;
		}
		else{ prev->right = curr->left;
		}
		delete curr;
        return;
	}
}

template<class T>
void Tree<T>::balance(T data[], int first, int last)
{
	if (first <= last) {
		int middle = (first + last) / 2;
		insert(data[middle]);
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);
	}
}

template<class T>
void Tree<T>::print(Node<T> *p) {

	if(!isEmpty()) {
	if (p != 0)
	{
		print(p->left);
		cout << p->key << " ";
		print(p->right);
	}
}
}


#endif // Binary_Search_Tree

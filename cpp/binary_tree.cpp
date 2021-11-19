#include<iostream>
#include<queue>
using namespace std;
// input : 1 2 4 -1 -1 5 7 -1 - 1 3 -1 6 -1 -1
// output : 1 2 4 5 7 3 6
// Inorder: 4,2,7,5,1,3,6
// postorder: 4,7,5,2,6,3,1
class Node{
public:
	int data;
	Node * left;
	Node * right;

	Node(int d){
		data = d;
		left = right = NULL;
	}
};
//preorder Build of the tree Root, right Tree
Node* buildTree(){

	int d;
    cin>>d;
    if(d==-1){
    	return NULL; 


    }
    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(Node *root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void postOrder(Node *root){
	if(root==NULL){
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<< root->data <<" ";
}

// Todo: Implement Level order Traversal
// Expected output

// 1
// 2 3
// 4 5 6 
// 7

void levelOrderPrint(Node*root){

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}

		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);

			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return;
}

Node* levelOrderBuild(){

	int d;
	cin>>d;

	Node* root = new Node(d);

	queue<Node*> q;

	q.push(root);

	while(!q.empty()){
		Node* current = q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			current->left = new Node(c1);
			q.push(current->left);
		}

		if(c2!=-1){
			current->right = new Node(c2);
			q.push(current->right);
		}

	}
	return root;
}

// class Tree{
// 	Node * root;
// 	// Methods
// }
// Helper function : Height of the tree 
int height(Node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1+max(h1,h2);
}

// Diameter
// Time complexity: O(N2)
int diameter(Node*root){
	// base case
	if(root==NULL){
		return 0;
	}
	// rec case
	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);

	return max(D1,max(D2,D3));
}

// Diameter---optimised

class HDPair{
public:
	int height;
	int diameter;


};

HDPair optDiameter(Node*root){
	HDPair p;

	if(root==NULL)
	{
		p.height = p.diameter = 0;
		return p;
	}
	// otherwise
	HDPair left = optDiameter(root->left);
	HDPair right = optDiameter(root->right);

	p.height = max(left.height,right.height) + 1;

	int D1 = left.height + right.height;
	int D2 = left.diameter;
	int D3 = right.diameter;

	p.diameter = max(D1,max(D2,D3));
	return p;

}
int main(){

	Node* root = levelOrderBuild();
	levelOrderPrint(root);

	cout<< diameter <<endl;

	cout<<" opt diameter is"<< optDiameter(root).diameter <<endl;;

	return 0;

}
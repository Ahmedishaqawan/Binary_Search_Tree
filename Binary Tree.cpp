#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int val){
	Node* temp =new Node();
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
} 
Node* insert(Node* root, int val){
	if(root==NULL){
		return newNode(val);
	}
	else{
		if(val<root->data){
			root->left=insert(root->left,val);
		}
		else{
			root->right=insert(root->right,val);
		}
	}
	return root;
} 
int treePathsSumUtil(Node* root,int val){
	if(root=NULL){
		return 0;
	}
	val=(val*10)+root->data;
	if(root->left==NULL && root->right==NULL){
		return val;
	}
	int sum =0;
	sum+=(treePathsSumUtil(root->left,val)+treePathsSumUtil(root->right,val));
	return sum;
}
int treePathSum(Node* root){
	treePathsSumUtil(root,0);
}
bool Mirror(Node* root1, Node* root2){
	if(root1==NULL && root2==NULL){
		return true;
	}
	else{
		if(root1 && root2 && root1->data == root2->data){
			return Mirror(root1->left,root2->right) && Mirror(root1->right,root2->left);
		}
		else{
			return false;
		}
	}
}
bool Symmetric(Node* root){
	Mirror(root,root);
}
int SameTree(Node* root1,Node* root2){
	if(root1==NULL && root2==NULL){
		return 1;
	}
	else{
		if(root1->data == root2->data){
		return SameTree(root1->left,root2->left) && SameTree(root1->right,root2->right);	
		}
	}
}
int maxDepth(Node* root){
	if(root==NULL){
		return 0;
	}
	else{
		int lDepth=maxDepth(root->left);
		int rDepth=maxDepth(root->right);
		if(lDepth>rDepth){
			return (lDepth+1);
		}
		else{
			return (rDepth+1);
		}
	}
}
int minDepth(Node* root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return 1;
	}
	int L = root->left!=NULL ? minDepth(root->left):INT_MAX;
	int R = root->right!=NULL ? minDepth(root->right):INT_MAX;
	return 1+min(L,R);
}
void inorder(Node* root){
	if(root!=NULL){
    inorder(root->left);
	cout<<root->data<<" ";	
	inorder(root->right);
	}
}
void preorder(Node* root){
	if(root!=NULL){
	cout<<root->data<<" ";
    preorder(root->left);	
	preorder(root->right);
	}
}
void postorder(Node* root){
	if(root!=NULL){
    postorder(root->left);	
	postorder(root->right);
	cout<<root->data<<" ";
	}
}
int main(){
	Node* root= new Node();
	root=NULL;
	int size,arr[50];
	cout<<"Enter the Size of the Binary Tree:";
	cin>>size;
	cout<<"Enter the Element of the Binary Tree:"<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	for(int i=0;i<size;i++){
		root=insert(root,arr[i]);
	}
	cout<<"InOrder Value Is:"<<endl;
	inorder(root);
	cout<<"PreOrder Value Is:"<<endl;
	preorder(root);
	cout<<"PostOrder Value Is:"<<endl;
	postorder(root);
	cout<<"Sum of Root to Leaf:"<<endl;
	cout<<treePathSum(root);
	if(Symmetric(root)){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
	cout<<"Trees are:";
	if(SameTree(root,root)){
		cout<<"Trees are Same";
	}else{
		cout<<"Tress are Not Same";
	}
	cout<<"Maximum Depth Is:";
	cout<<maxDepth(root);
	cout<<minDepth(root);
	return 0;
}

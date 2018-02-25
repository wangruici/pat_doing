#include <cstdio>
#include <vector>

using std::vector;

struct node{
	int data;
	node *left,*right;
};

void node_insert(node **root,int data){
	if((*root)==NULL){
		(*root)=new node;
		(*root)->data=data;
		(*root)->left=(*root)->right=NULL;
		return;
	}
	else if((*root)->data>data){
		node_insert(&((*root)->left),data);
	}
	else{
		node_insert(&((*root)->right),data);
	}
}

/*
void node_insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	else if((root->data)>data){
		node_insert(root->left,data);
	}
	else{
		node_insert(root->right,data);
	}
}
*/

void preOrder(node* root,vector<int>&vi){
	if(root==NULL){
		return;
	}
	else{
		vi.push_back(root->data);
		preOrder(root->left,vi);
		preOrder(root->right,vi);

	}
}

void preOrderMirror(node* root,vector<int>&vi){
	if(root==NULL){
		return;
	}
	else{
		vi.push_back(root->data);
		preOrderMirror(root->right,vi);
		preOrderMirror(root->left,vi);
	}
}

void postOrder(node* root,vector<int>&vi){
	if(root==NULL){
		return;
	}
	else{
		postOrder(root->left,vi);
		postOrder(root->right,vi);
		vi.push_back(root->data);
	}
}

void postOrderMirror(node* root,vector<int>&vi){
	if(root==NULL){
		return;
	}
	else{
		postOrderMirror(root->right,vi);
		postOrderMirror(root->left,vi);
		vi.push_back(root->data);
	}
}

vector<int> origin,pre,preMirror,post,postMirror;
int main(){
	int count,data;
	node* root=NULL;
	scanf("%d",&count);
	for(int i=0;i<count;++i){
		scanf("%d",&data);
		origin.push_back(data);
		node_insert(&root,data);
	}

	preOrder(root,pre);
	preOrderMirror(root,preMirror);
	postOrder(root,post);
	postOrderMirror(root,postMirror);
	if(origin==pre){
		printf("YES\n");
		for(int i=0;i<(int)post.size();++i){
			printf("%d",post[i]);
			if(i<(int)post.size()-1) printf(" ");
		}
	}
	else if(origin==preMirror){
		printf("YES\n");
		for(int i=0;i<(int)postMirror.size();++i){
			printf("%d",postMirror[i]);
			if(i<(int)postMirror.size()-1) printf(" ");
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}





node* create(int preL,int preR,int inL,int inR){
	//[preL,preR]is the rank of preorder
	//[inL,inR]is the rank of inorder中序遍历
	if(preL>preR){
		return NULL;
	}

	node* root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;++k){
		if(in[k]==pre[preL])
			break;
	}

	int numLeft=k-inL;

	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	root->rchild=create(preL+numLeft+1,preR,k+1,inR);

	return root;
}

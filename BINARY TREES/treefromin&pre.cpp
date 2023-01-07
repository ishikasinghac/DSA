map<int,int>m;
       for(int i=0;i<inorder.size();i++)
       {
           m[inorder[i]]=i;
       }
       TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
       return root;
       TreeNode* buildTree(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend, map<int,int>m);
       if(prestart>preend || instart>inorder)
       return NULL;
       TreeNode* root=new TreeNode(preorder[prestart]);
       int inroot= map[root->val];
       int numsleft=inroot-instart;
       root->left=buildTree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,m);
       root->right=buildTree(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,m);
 
return root;

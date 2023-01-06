class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return dfsheight(root)!=-1;
    }
    int dfsheight(Node *root)
    {
        if(root==NULL)
        return 0;
        int leftheight=dfsheight(root->left);
        if(leftheight==-1)
        return -1;
        int rightheight=dfsheight(root->right);
        if(rightheight==-1)
        return -1;
        if(abs(leftheight-rightheight)>1)
        return -1;
        
        return max(leftheight,rightheight)+1;
    }
};

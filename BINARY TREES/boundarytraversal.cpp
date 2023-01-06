class Solution {
    
    void lefttree(Node *root,vector<int>&res)
    {
       if(!root)
       return;
       if(root->left)
       {
           res.push_back(root->data);
           lefttree(root->left,res);
       }
       else if(root->right)
       {
           res.push_back(root->data);
           righttree(root->right,res);
       }
    }
    void righttree(Node *root,vector<int>&res)
    {
       if(!root)
       return;
       if(root->right)
       {
           res.push_back(root->data);
           righttree(root->right,res);
       }
       else if(root->left)
       {
           res.push_back(root->data);
           lefttree(root->left,res);
       }
    }
    void leaf(Node *root,vector<int>&res)
    {
       if(!root)
       return;
       leaf(root->left,res);
       if(!root->left && !root->right)
       res.push_back(root->data);
       leaf(root->right,res);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>res;
        res.push_back(root->data);
        lefttree(root->left,res);
        leaf(root,res);
        righttree(root->right,res);
        
        
    }
};

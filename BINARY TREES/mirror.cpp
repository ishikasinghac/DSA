void mirror(Node* root)
{
   if(root==NULL)
   return;
   mirror(root->left);
   mirror(root->right);
   swap(root->left,root->right);
}

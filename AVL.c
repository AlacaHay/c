#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    int height;
    struct Node* right,*left;
}Node;
Node* CreateNode(int data){
    Node * newNode=(Node*)calloc(1,sizeof(Node));
    newNode->data=data;
    newNode->height=1;
    return newNode;
}

int Height(Node* root){
    if(!root) return 0;
    else
        return root->height;
    
}
int getBalance(Node*root){
    if(root==NULL) return 0;
    return Height(root->left)-Height(root->right);
}
Node* rightRotate(Node* root){
    Node* solCocuk= root->left;
    root->left=solCocuk->right;
    solCocuk->right=root;

    //Yukseklikler guncelleniyor.
    root->height=1+(Height(root->left)>Height(root->right)? Height(root->left): Height(root->right));
    solCocuk->height=1+(Height(solCocuk->left)>Height(solCocuk->right)? Height(solCocuk->left):Height(solCocuk->right));

    return solCocuk; // yeni kok artik sol cocuk oldu.
}
Node* leftRotate(Node*root){
    Node* sagCocuk=root->right;
    root->right=sagCocuk->left;
    sagCocuk->left=root;
    root->height=1+(Height(root->left)>Height(root->right)? Height(root->left): Height(root->right));
    sagCocuk->height=1+(Height(sagCocuk->left)>Height(sagCocuk->right)? Height(sagCocuk->left):Height(sagCocuk->right));

    return sagCocuk;
}
Node* insert(Node* root,int val){  //ekleme fonksiyonu ozyinelemeli olarak cagrilir.
    if(root==NULL) return CreateNode(val);
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else return root; // tekrarli eklemeyi engeller.Ayni degeri eklenmez yani.

    root->height=1+(Height(root->left)>Height(root->right)? Height(root->left): Height(root->right));
    int balance=getBalance(root);
    //left left
    if(balance>1 && val<root->left->data){
        return rightRotate(root);
    }
    //Left right rotate
    if(balance>1&& val>root->left->data){
        root->left=leftRotate(root->left);
        root=rightRotate(root);
        return root;
    }
    // Right right rotation
    if(balance<-1 && val>root->right->data){
        root=leftRotate(root);
        return root;
    }
    //Right left rotation
    if(balance<-1&& val<root->right->data){
        root->right=rightRotate(root->right);
        root=leftRotate(root);
        return root;
    }

    //denge bozacak bir case yoksa 
    return root;


}
int maxNode(Node*root){
    if(root==NULL) return 0;
   else{
            Node* iter=root;
            while(iter->right!=NULL){
                iter=iter->right;
            }
            return iter->data;
        }
}

Node* deletion(Node*root,int val){
    if(root==NULL) return NULL;
    if(val<root->data){
        root->left=deletion(root->left,val);
    }
    else if(val>root->data){
        root->right=deletion(root->right,val);
    }
    else{
        //2 cocuk varsa
        if(root->right!=NULL&& root->left!=NULL){
            int maxLeft=maxNode(root->left);
            root->data=maxLeft;
            root->left=deletion(root->left,maxLeft);
        }
        else{
        //Tek cocuk ya da cocuk yoksa
        Node* temp=root;
        if(root->left==NULL){
            root=root->right;
        }
        else if(root->right==NULL){
            root=root->left;
        }
        else{
            root=NULL;
        }
        free(temp);
    }

}
    
    if(root==NULL) return root;  //root disinda eleman kalmadiysa
    root->height=1+(Height(root->left)>Height(root->right)? Height(root->left): Height(root->right));
    int balance=getBalance(root);
    if(balance >1&& getBalance(root->left)>=0)
    {
        root=rightRotate(root);
        return root;
    }
    //silinen  sagdan solun da balanci  neg. ise iki rotation yapariz. 
     if(balance >1&& getBalance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        root=rightRotate(root);
        return root;
    }
    //soldan silinmis
    if(balance<-1&& getBalance(root->right)<=0){
        root=leftRotate(root);
        return root;
    }
    if(balance<-1&& getBalance(root->right)>0){
        root->right=rightRotate(root->right);
        root=leftRotate(root);
        return root;
    }
    return root; // dengeliyse rootu doner.

}
void inorder(Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
int main(){
    Node*root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    inorder(root);
    
    printf("\n%d\n",root->data);
    root=deletion(root,5);
    root=deletion(root,6);
    inorder(root);
    printf("\n%d\n",root->data);

}
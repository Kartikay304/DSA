#include <stdio.h>
#include <stdlib.h>

typedef struct TREE {
    int data;
    struct TREE *rightchild;
    struct TREE *leftchild;
}T;

T *root=NULL;

void insertion() {
    T *new_node=(T*)malloc(sizeof(T));
    T *current;
    T *parent;
    int data,ch;
    printf("Enter data::");
    scanf("%d",&data);
    new_node->data=data;
    new_node->leftchild=NULL;
    new_node->rightchild=NULL;
    if(root==NULL) root=new_node;
    else {
        current=root;
        parent=current;
        printf("\nMENU\n1.Left child\n2.Right_child\n");
        printf("Enter your choice(left or right)::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: current=current->leftchild; if(current==NULL) parent->leftchild=new_node; break;
            case 2: current=current->rightchild; if(current==NULL) parent->rightchild=new_node; break;
        }
    }
}

void print_preorder(T *tree) {
    if (tree) {
        printf("%d->",tree->data);
        print_preorder(tree->leftchild);
        print_preorder(tree->rightchild);
    }
}

void print_inorder(T *tree) {
    if (tree) {
        print_inorder(tree->leftchild);
        printf("%d->",tree->data);
        print_inorder(tree->rightchild);
    }
}

void print_postorder(T *tree){
    if (tree) {
        print_postorder(tree->leftchild);
        print_postorder(tree->rightchild);
        printf("%d->",tree->data);
    }
}

void bfs_level(T *tree,int h) {
    if(tree==NULL) return;
    if(h==1) printf("%d ",tree->data);
    else {
        bfs_level(tree->leftchild, h-1);
        bfs_level(tree->rightchild, h-1);
    }
}

int height(T *tree){
    if(tree==NULL) return 0;
    else {
        int lheight = height(tree->leftchild);
        int rheight =height(tree->rightchild);

        if(lheight>rheight) return (lheight+1);
        else return(rheight+1);
    }
}

void bfs_order(T *tree) {
    int h=height(tree),i;
    for(i=0;i<=h;i++) bfs_level(tree,i);
}

void display(T *tree) {
    printf("\nPreorder::");
    print_preorder(tree);
    printf("\nInorder::");
    print_inorder(tree);
    printf("\nPostrder::");
    print_postorder(tree);
    printf("\n\n");
    bfs_order(tree);
}

int main() {
    int ch;
    printf("\n<----------------->\n");
    printf("|        MENU     |\n");
    printf("<----------------->\n");
    printf("|    1.Insert     |\n");
    printf("|    2.Display    |\n");
    printf("|    3.Exit       |\n");
    printf("<----------------->\n");
    while(1) {
        printf("\nEnter your choice(1-3)::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insertion(); break;
            case 2: display(root); break;
            case 3: exit(0); break;
        }
    }
    return 0;
}
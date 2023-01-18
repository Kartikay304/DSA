#include <stdio.h>
#include <stdlib.h>

typedef struct TREE {
    int data;
    struct TREE *left_child;
    struct TREE *right_child;
}T;

//------------------------------------------------------------------------------------------INSERTION

T *new_node(int data) {
    T *new_node=(T*)malloc(sizeof(T));
    new_node->left_child=new_node->right_child=NULL;
    new_node->data=data;
    return new_node;
}

T *insert(T *node,int data) {
    if(node==NULL) return new_node(data);
    if(data<node->data) node->left_child=insert(node->left_child,data);
    else node->right_child=insert(node->right_child,data);
    return node;
}

//------------------------------------------------------------------------------------------DELETION

T *min_right(T *node) {
    T *current=node;
    while(current && current->left_child!=NULL) current=current->left_child;
    return current;
}

T *delete(T *node,int key) {
    if(node==NULL) return node;
    if(key<node->data) node->left_child=delete(node->left_child,key);
    else if(key>node->data) node->right_child=delete(node->right_child,key);
    else {
        if(node->left_child==NULL) {
            T *temp=node->right_child;
            free(node);
            return temp;
        }
        else if(node->right_child==NULL) {
            T *temp=node->left_child;
            free(node);
            return temp;
        }

        T *temp=min_right(node->right_child);
        node->data=temp->data;
        node->right_child=delete(node->right_child,temp->data); 
    }
    return node;
}

//--------------------------------------------------------------------------------------------DISPLAY

void dfs_preorder(T *node) {
    if(node==NULL) return;
    printf("%d ",node->data);
    dfs_preorder(node->left_child);
    dfs_preorder(node->right_child);
}
void dfs_inorder(T *node) {
    if(node==NULL) return;
    dfs_inorder(node->left_child);
    printf("%d ",node->data);
    dfs_inorder(node->right_child);
}
void dfs_postorder(T *node) {
    if(node==NULL) return;
    dfs_postorder(node->left_child);
    dfs_postorder(node->right_child);
    printf("%d ",node->data);
}

int height(T *node) {
    if(node==NULL) return 0;
    else {
        int lheight=height(node->left_child);
        int rheight=height(node->right_child);
        if(lheight>rheight) return (lheight+1);
        else return (rheight+1);
    }
}

void bfs_level(T *node,int h) {
    if(node==NULL) return;
    if(h==1) printf("%d ",node->data);
    else {
        bfs_level(node->left_child,h-1);
        bfs_level(node->right_child,h-1);
    }
}

void bfs(T *node) {
    int h=height(node);
    for(int i=0;i<=h;i++) bfs_level(node,i);
}

void display(T *node) {
    printf("\n------DFS------\n");
    printf("Preorder\n");
    dfs_preorder(node);
    printf("\nInorder\n");
    dfs_inorder(node);
    printf("\nPostorder\n");
    dfs_postorder(node);
    printf("\n------BFS------\n");
    bfs(node);
}

//----------------------------------------------------------------------------------------------SEARCH

int search(T *node,int key) {
    if(node->data==key) return 1;
    else return 0;
    if(key<node->data) search(node->left_child,key);
    else search(node->right_child,key);
}

//-----------------------------------------------------------------------------------------------DRIVER_CODE

int main() {
    int data,ch,flag=0;
    T *root=NULL;
    printf("\nMENU\n1.INSERT\n2.DELETE\n3.SEARCH\n4.DISPLAY\n5.EXIT\n");
    while(1) {
        printf("\nEnter your choice::");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter data::");
                scanf("%d",&data);
                root=insert(root,data);
            break;

            case 2: printf("Enter key::");
                scanf("%d",&data);
                root=delete(root,data); 
            break;

            case 3: printf("Enter key::");
                scanf("%d",&data);
                flag=search(root,data);
                (flag==1)?printf("Key Found"):printf("Key Not Found");
            break;

            case 4: display(root); 
                printf("\n");
                break;
            
            case 5: exit(0);
        }
    }
}
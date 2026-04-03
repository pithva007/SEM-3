#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    struct Node *left, *right;
};

struct Node* newNode(char name[], char phone[]){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    strcpy(p->name, name);
    strcpy(p->phone, phone);
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct Node* addEntry(struct Node* root, char name[], char phone[]) {
    if(root==NULL) return newNode(name, phone);

    if(strcmp(name,root->name) < 0){
        root->left = addEntry(root->left, name, phone);
    }
    else if(strcmp(name,root->name) > 0){
        root->right = addEntry(root->right, name, phone);
    }
    else printf("Name already exists!\n");

    return root;
}

struct Node* minNode(struct Node* root) {
    while(root && root->left){
        root = root->left;
    }
    return root;
}

struct Node* delEntry(struct Node* root, char name[]) {
    if(root == NULL){
        printf("Name not found!\n");
        return root;
    }

    if(strcmp(name, root->name) < 0){
        root->left = delEntry(root->left,name);
    }else if(strcmp(name, root->name) > 0){
        root->right = delEntry(root->right,name);
    }
    else{
       if((root->left ==  NULL) || (root->right == NULL)){
       struct Node* temp;
       if(root->left != NULL){
           temp = root->left;
       }
       else temp = root->right;
       free(root);
       return temp;
    }

    struct Node* temp = minNode(root->right);
    strcpy(root->name, temp->name);
    strcpy(root->phone, temp->phone);
    root->right = delEntry(root->right, temp->name);
    }
    return root;
}

void searchEntry(struct Node* root, char name[]){
    if(root == NULL){
        printf("Name not found!\n");
        return;
    }

    int cmp = strcmp(name, root->name);
    if(cmp == 0){
        printf("Phone of %s: %s\n", root->name, root->phone);
    }
    else if(cmp<0){
        searchEntry(root->left, name);
    }
    else searchEntry(root->right, name);
}

void inorder(struct Node* root){
    if(root){
        inorder(root->left);
        printf("%s :\t %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

void revInorder(struct Node* root) {
    if(root){
        revInorder(root->right);
        printf("%s :\t %s\n", root->name, root->phone);
        revInorder(root->left);
    }
}

int main(){
    struct Node* root = NULL;
    int ch;
    char name[50], phone[15];

    while(1){
        printf("\nTasks:\n");
        printf("1. Add Entry\n2. Delete Entry\n3. Search\n4. Show Asc\n5. Show Desc\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        

        switch(ch){
            case 1:
                printf("Name: ");
                scanf(" %s",name);
                printf("Phone: ");
                scanf(" %s",phone);
                root = addEntry(root, name, phone);
                break;

            case 2:
                printf("Enter name to delete: ");
                scanf(" %s", name);
                root = delEntry(root, name);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf(" %s", name);
                searchEntry(root, name);
                break;

            case 4:
                printf("\n Ascending Order:\n");
                inorder(root);
                break;

            case 5:
                printf("\nDescending Order :\n");
                revInorder(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

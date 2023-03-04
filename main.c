//C program to print binary tree reverse level order traversal
#include <stdio.h>
#include <stdlib.h>
//A binary tree node has data, pointer to left and right child
struct treeNode
{
    int data;
    struct treeNode* leftptr;
    struct treeNode* rightptr;
};
//Function prototypes
void reverseLevelOrder(struct treeNode* root);
struct treeNode* newNode(int data);
//Print function of reverse level order
void print(struct treeNode* array[],int index){
    for (int i = index-1; i >= 0; i--) {
        printf("%d\t",array[i]->data);
    }
}
//add function is for adding items into struct array from root
void add(struct treeNode* array[],struct treeNode* item,int *curr){
    array[*curr]=item;
    (*curr)++;
}
//Function to print reverse level order traversal a binary tree
void reverseLevelOrder(struct treeNode* root)
{
    struct treeNode* arr[50]; //struct array is for store elements of tree
    //curr is the last non empty index of arr
    //temp index is using for control of whether node has leaf
    int tempIndex = 0, curr = 0;
    // Explanation :
    // (tempIndex=0,curr=0)
    // We throw the first node in root(9) into the struct array arr. (arr={9}) (tempIndex=0,curr=1)(arr={9})
    // Then,in while loop: (tempIndex=1,curr=1)
    // If temp(9) has right node(21) add function runs : (arr={9,21}) (tempIndex=1,curr=2)
    // If temp(9) has left node(12) add function runs: (arr={9,21,12}) (tempIndex=1,curr=3)
    // Temp points to second level right node(21).
    // (tempIndex=2,curr=3)
    // If temp(21) has right node(11) add function runs: (arr={9,21,12,11}) (tempIndex=2,curr=4)
    // If temp(21) has left node(7) add function runs: (arr={9,21,12,11,7}) (tempIndex=2,curr=5)
    // Temp points to second level left node(12).
    // (tempIndex=3,curr=5)
    // If temp(12) has right node(8) add function runs: (arr={9,21,12,11,7,8}) (tempIndex=3,curr=6)
    // If temp(12) has left node(7) add function runs: (arr={9,21,12,11,7,8,15}) (tempIndex=3,curr=7)
    // Temp points to third level (21)'s right node(11).
    // (tempIndex=4,curr=7) If conditions are not run.
    // Temp points to third level (21)'s left node(7).
    // (tempIndex=5,curr=7) If conditions are not run.
    // Temp points to third level (12)'s right node(8).
    // (tempIndex=6,curr=7) If conditions are not run.
    // Temp points to third level (12)'s left node(15).
    // (tempIndex=7,curr=7) If conditions are not run.
    // While loop ends (tempIndex = curr)
    // Lastly, we write reverse order of struct array arr.
    // I wrote only the data of struct nodes in comment lines for easy to see!

    add(arr, root, &curr);//this is for assigning root data to array

    if(root!=NULL) {//if tree is not empty
        while (tempIndex < curr) {
            struct treeNode *temp = arr[tempIndex]; //temp is for traversing tree
            tempIndex++;
            if (temp->rightptr != NULL) {//if temp has right child first we add this child into the arr
                add(arr, temp->rightptr, &curr);
            }
            if (temp->leftptr != NULL) {//then if temp has left child we add this child into arr
                add(arr, temp->leftptr, &curr);
            }
        }
    }
    print(arr,curr);//print function of reverse level order traversal a binary tree
}
//Insert new node to the binary tree
struct treeNode* newNode(int data)
{
    struct treeNode* treeNode = (struct treeNode*) malloc(sizeof(struct treeNode));
    treeNode->data = data;
    treeNode->leftptr = NULL;
    treeNode->rightptr = NULL;
    return(treeNode);
}
int main() {
    struct treeNode *root = newNode(9);
    root->leftptr = newNode(12);
    root->rightptr = newNode(21);
    root->leftptr->leftptr = newNode(15);
    root->leftptr->rightptr = newNode(8);
    root->rightptr->leftptr = newNode(7);
    root->rightptr->rightptr = newNode(11);
    printf("Level Order traversal of binary tree is \n");
    reverseLevelOrder(root);
    return 0;
}

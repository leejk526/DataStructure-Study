#include <stdio.h>
#include "BinaryTree.h"

void print_function(BTData data) {
    printf("%d ", data);
}

int main() {

    printf("Hello world!\n");

    BTreeNode* N1 = MakeBTreeNode();
    BTreeNode* N2 = MakeBTreeNode();
    BTreeNode* N3 = MakeBTreeNode();
    BTreeNode* N4 = MakeBTreeNode();
    BTreeNode* N5 = MakeBTreeNode();
    BTreeNode* N6 = MakeBTreeNode();

    SetData(N1, 1);
    SetData(N2, 2);
    SetData(N3, 3);
    SetData(N4, 4);
    SetData(N5, 5);
    SetData(N6, 6);

    MakeLeftSubTree(N1, N2);
    MakeRightSubTree(N1, N3);
    MakeLeftSubTree(N2, N4);
    MakeRightSubTree(N2, N5);
    MakeLeftSubTree(N3, N6);

//    printf("N4's data is %d\n",GetData(GetLeftSubTree(GetLeftSubTree(N1))) );
    printf("InorderTraverse\n");
    InorderTraverse(N1, print_function);
    printf("\n");
    printf("PreorderTraverse\n");
    PreorderTraverse(N1, print_function);
    printf("\n");
    printf("PostorderTraverse\n");
    PostorderTraverse(N1, print_function);
    printf("\n");

    printf("Destructor works\n");
    DeleteTree(N1);
}

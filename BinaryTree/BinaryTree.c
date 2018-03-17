#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

BTreeNode * MakeBTreeNode(void) {
    // Make a BinaryTree Node
    BTreeNode * nd = (BTreeNode *) malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode * bt) {
    // Get data in BinaryTree Node
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data) {
    // Set data to BTree Node
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
    if(main->left != NULL) free(main->left);
    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
    if(main->right != NULL) free(main->right);
    main->right = sub;
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action) {
    // left mid right
    if (bt != NULL) {
        InorderTraverse(GetLeftSubTree(bt), action);
        action(bt->data);
//        printf("InorderTraverse %d\n",bt->data);
        InorderTraverse(GetRightSubTree(bt), action);
    }
}
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return ;
    }
    action(bt->data);
//    printf("PreorderTraverse %d\n", bt->data);
    PreorderTraverse(GetLeftSubTree(bt), action);
    PreorderTraverse(GetRightSubTree(bt), action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }
    PostorderTraverse(GetLeftSubTree(bt), action);
    PostorderTraverse(GetRightSubTree(bt), action);
//    printf("PostorderTraverse %d\n", bt->data);
    action(bt->data);
}

void DeleteTree(BTreeNode * bt) {
    BTreeNode * LT = GetLeftSubTree(bt);
    BTreeNode * RT = GetRightSubTree(bt);
    if (LT != NULL) {
        DeleteTree(LT);
    }
    if (RT != NULL) {
        DeleteTree(RT);
    }
    printf("delete %d\n", bt->data);
    free(bt);
}

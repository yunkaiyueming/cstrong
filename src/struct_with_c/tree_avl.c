//平衡二叉树的C实现
#include <stdio.h>
#include <stdlib.h>

//平衡二叉树的结构体
typedef int elementType;
typedef struct AVLNODE
{
    elementType data;
    struct AVLNODE *left;
    struct AVLNODE *right;
    int height;        //以此节点为根，树的高度；
    unsigned int freq; //此节点保存的数据出现的频率
} AvlNode, *PtrToNode;

// return the height of node ptrTree or -1 if NULL;
//只有一个根节点的高度为0，空树的高度-1
int NodeHeight(PtrToNode ptrTree)
{
    return ptrTree == NULL ? -1 : ptrTree->height;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

//LL旋转
void RotateWithLeft(PtrToNode k1)
{
    PtrToNode k = k1->left; //保存节点的左子树
    k1->left = k->right;    //k节点的右子树作为k1的左子树
    k->right = k1;          //把k1的k的右子树
    //到此树旋转完成，更新树的深度,以k，k1为节点的树的深度发生了变化；
    k1->height = max(NodeHeight(k1->left), NodeHeight(k1->right)) + 1;
    k->height = max(NodeHeight(k->left), NodeHeight(k->right)) + 1;
    //根节点发生了变化，右k1变为了k，因为传的参数是引用，程序默认k1为根节点
    //k为局部变量，离开作用域，变量就会销毁，因此需要返回根节点，只不过是通过引用的方式罢了；
    k1 = k;
}

//R旋转
void RotateWithRight(PtrToNode k2)
{
    PtrToNode k = k2->right; //保存节点的右子树
    k2->right = k->left;
    k->left = k2;
    //到此树旋转完成，更新树的深度,以k，k1为节点的树的深度发生了变化；
    k2->height = max(NodeHeight(k2->left), NodeHeight(k2->right)) + 1;
    k->height = max(NodeHeight(k->left), NodeHeight(k->right)) + 1;
    //根节点发生了变化，右k1变为了k，因为传的参数是引用，程序默认k1为根节点
    //k为局部变量，离开作用域，变量就会销毁，因此需要返回根节点，只不过是通过引用的方式罢了；
    k2 = k;
}

void DoubleRotateWithLeft(PtrToNode k3)
{
    RotateWithRight(k3->left);
    RotateWithLeft(k3);
}

void DoubleRotateWithRight(PtrToNode k3)
{
    RotateWithLeft(k3->right);
    RotateWithRight(k3);
}

//左平衡处理
void LeftBalance(PtrToNode node)
{
    PtrToNode ptrTmp = node->left;
    if (NodeHeight(ptrTmp->left) - NodeHeight(ptrTmp->right) == -1)
    {
        //右子树高于左子树，在右子树插入的
        DoubleRotateWithLeft(node); //LR
    }
    else
    {
        RotateWithLeft(node); //LL
    }
}

//右平衡处理
void RightBalance(PtrToNode node)
{
    PtrToNode ptrTmp = node->right;
    if (NodeHeight(ptrTmp->right) - NodeHeight(ptrTmp->left) == -1)
    {                                //左子树比右子树高，说明在左子树插入的
        DoubleRotateWithRight(node); //RL
    }
    else
    {
        RotateWithRight(node); //RR
    }
}

PtrToNode AVL_Init()
{
    PtrToNode node = (PtrToNode)malloc(sizeof(AvlNode));
    node->data = 1;
    node->height = 0;
    node->freq = 1;
    node->left = NULL;
    node->right = NULL;

    printf("init node data:%d\n", node->data);
    return node;
}

//节点写入
void AVL_Insert(AvlNode *node, elementType x)
{
    if (NULL == node) //找到插入的节点的位置
    {
        node = (AvlNode *)malloc(sizeof(AvlNode));
        node->data = x;
        node->height = 0;
        node->freq = 1;
        node->left = NULL;
        node->right = NULL;

        printf("insert init node data:%d\n", node->data);
    }
    else if (x < node->data) //在左子树插入
    {
        printf("left insert \n");
        AVL_Insert(node->left, x);
        printf("left insert after：%d", node->left->data);
        //判断是否破坏AVL树的平衡性
        if (NodeHeight(node->left) - NodeHeight(node->right) == 2)
            LeftBalance(node); //左平衡处理
    }
    else if (node->data < x) //在右子树插入
    {
        printf("right insert \n");
        AVL_Insert(node->right, x);
        //判断是否破坏AVL树的平衡性
        if (NodeHeight(node->right) - NodeHeight(node->left) == 2)
            RightBalance(node); //右平衡处理
    }
    else
    {
        node->freq++;
    }

    node->height = max(NodeHeight(node->left), NodeHeight(node->right)) + 1; //更新树的高度
    printf("tree height %d \n", node->height);
}

PtrToNode AVL_Find(PtrToNode node, elementType x)
{
    if (node == NULL) //没找到元素
    {
        return NULL;
    }
    else if (x < node->data)
    {
        return AVL_Find(node->left, x); //在左子树里面查找
    }
    else if (node->data < x)
    {
        return AVL_Find(node->right, x); //在右子树里面查找
    }
    else //相等
        return node;
}

void AVL_Delete(PtrToNode node, elementType x)
{
    if (NULL == node) //空树直接返回
        return;
    if (x < node->data) //在左子树中查找
    {
        AVL_Delete(node->left, x);
        if (NodeHeight(node->right) - NodeHeight(node->left) == 2) //树左平衡处理
            RightBalance(node);
    }
    else if (node->data < x) //在右子树中查找
    {
        AVL_Delete(node->right, x);
        if (NodeHeight(node->left) - NodeHeight(node->right) == 2) //树右平衡处理
            LeftBalance(node);
    }
    else //找到要删除的元素节点
    {
        if (node->left == NULL) //左子树为空
        {
            PtrToNode ptrTmp = node;
            node = node->right; //用右孩子代替此节点
            free(ptrTmp);       //释放内存
        }
        else if (node->right == NULL) //右子树为空
        {
            PtrToNode ptrTmp = node;
            node = node->left; //用左孩子代替此节点
            free(ptrTmp);
        }
        else //左右子树都不为空
        {
            //一般的删除策略是左子树的最小数据 或 右子树的最小数据 代替该节点
            PtrToNode ptrTmp = node->left; //从左子树中查找
            while (ptrTmp->right != NULL)
                ptrTmp = ptrTmp->right;
            //此时的ptrTmp指向左子树中的最大元素
            node->data = ptrTmp->data;
            AVL_Delete(node->left, ptrTmp->data); //递归的删除该节点
        }
    }

    //更新节点的高度
    if (node)
        node->height = max(NodeHeight(node->left), NodeHeight(node->right));
}

//中序遍历
void print(PtrToNode root)
{
    if (NULL == root)
    {
        printf("tree is null");
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int main()
{
    //C++引入的引用概念，可以直接对树的节点进行插入操作，而不用返回树的根节点
    //PtrToNode root = NULL;
    //PtrToNode root = AVL_Init();

    AvlNode root = {};

    //printf("get %d\n", root->data);
    printf("1111");
    AVL_Insert(&root, 4);
    printf("222");

    AVL_Insert(&root, 2);
    AVL_Insert(&root, 6);
    AVL_Insert(&root, 1);
    AVL_Insert(&root, 3);
    AVL_Insert(&root, 5);
    AVL_Insert(&root, 7);
    AVL_Insert(&root, 16);
    AVL_Insert(&root, 15);
    print(&root);
    printf("3333");
    printf("%d \n", root.height);
    printf("44444");
    AVL_Delete(&root, 15);
    AVL_Delete(&root, 5);
    printf("5555");
    print(&root);
    PtrToNode y = AVL_Find(&root, 15);
    if (y == NULL)
    {
        printf("没有查找到15\n");
    }
    else
    {
        printf("所在节点的高度：%d\n", y->height);
        if (NULL != y->left)
        {
            printf("所在节点的左孩子：%d\n", y->left->data);
        }
        if (NULL != y->right)
        {
            printf("所在节点的右孩子：%d\n", y->right->data);
        }
    }
}
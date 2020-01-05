#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

//C实现字典树
typedef struct TrieNode
{
    int nCount;                 // 该节点前缀 出现的次数
    struct TrieNode *next[MAX]; // 该节点的后续节点
} TrieNode;

TrieNode Memory[1000000];
int allocp = 0;

//初始化一个节点。
TrieNode *createTrieNode()
{
    TrieNode *tmp = &Memory[allocp++];
    tmp->nCount = 1;
    int i;
    for (i = 0; i < MAX; i++)
        tmp->next[i] = NULL;
    return tmp;
}

void insertTrie(TrieNode **pRoot, char *str)
{
    TrieNode *tmp = *pRoot;
    int i = 0, k;
    while (str[i])
    {
        k = str[i] - 'a';
        printf("%c ==> %d \n", str[i], k);
        if (tmp->next[k])
        {
            tmp->next[k]->nCount++;
        }
        else
        {
            tmp->next[k] = createTrieNode();
        }

        tmp = tmp->next[k];
        i++;
    }
}

int searchTrie(TrieNode *root, char *str)
{
    if (root == NULL)
        return 0;
    TrieNode *tmp = root;
    int i = 0, k;
    while (str[i])
    {
        k = str[i] - 'a';
        if (tmp->next[k])
        {
            tmp = tmp->next[k];
        }
        else
            return 0;
        i++;
    }
    return tmp->nCount;
}

int main(void)
{
    char s[100];
    TrieNode *Root = createTrieNode();
    while (gets(s) && s[0]!='0') //读入0 结束
    {
        printf("%s %d\n", s, (int)strlen(s));
        insertTrie(&Root, s);
    }

    printf("input start find: \n");
    while (gets(s) && s[0]!='0') //查询输入的字符串
    {
        printf("%d\n", searchTrie(Root, s));
    }

    return 0;
}
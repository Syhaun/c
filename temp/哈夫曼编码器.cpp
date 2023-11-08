#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256
typedef struct Node
{
    char data;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;
Node* createNode(char data,int frequency)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* buildHuffmanTree(char data[],int frequency[],int size)
{
    Node **leafNodes = (Node **)malloc(size * sizeof(Node *));
    for (int i = 0; i < size; i++)
    {
        leafNodes[i] = createNode(data[i], frequency[i]);
    }
    while(size > 1)
    {
        int min1 = 0;
        int min2 = 1;
        if(leafNodes[min1] -> frequency > leafNodes[min2]
        -> frequency)
        {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (int i = 2; i < size; i++)
        {
            if(leafNodes[i] -> frequency < leafNodes[min1]->frequency)
            {
                min2 = min1;
                min1 = i;
            }
            else if (leafNodes[i]->frequency < leafNodes[min2] ->frequency)
            {
                min2 = i;
            }
        }
        Node *inNode = createNode('$', leafNodes[min1]->frequency + leafNodes[min2]->frequency);
            inNode->left = leafNodes[min1];
            inNode->right = leafNodes[min2];
            leafNodes[min1] = inNode;

            for (int i = min2; i < size - 1; i++)
                leafNodes[i] = leafNodes[i + 1];
            size--;
    }
    Node *root = leafNodes[0];
    free(leafNodes);
    return root;
}
void writeEncodedTextToFile(const char *filename, const char *encodedText)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    fputs(encodedText, file);
    fclose(file);
}
int main()
{
    char filename[] = "D:\\代码文件夹集\\c语言\\temp\\SourceFile.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("文件打开失败!\n");
        return 1;
    }
    int charFrequency[MAX_SIZE] = {0};
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        charFrequency[ch]++;
    }
    fclose(file);
    printf("字符出现的频率为:\n");
    char data[MAX_SIZE];
    int frequency[MAX_SIZE];
    int size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (charFrequency[i] > 0)
        { 
            data[i] = i;
            frequency[i] = charFrequency[i];
            printf("字符: %c  频率: %d\n",data[i],frequency[i]);
        }
        size++;
    }
    Node *root = buildHuffmanTree(data, frequency, size);
    return 0;
}
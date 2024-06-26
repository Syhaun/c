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

Node *createNode(char data, int frequency)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *buildHuffmanTree(char data[], int frequency[], int size)
{
    Node **leafNodes = (Node **)malloc(size * sizeof(Node *));
    for (int i = 0; i < size; i++)
    {
        leafNodes[i] = createNode(data[i], frequency[i]);
    }
    while (size > 1)
    {
        int min1 = 0;
        int min2 = 1;
        if (leafNodes[min1]->frequency > leafNodes[min2]->frequency)
        {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (int i = 2; i < size; i++)
        {
            if (leafNodes[i]->frequency < leafNodes[min1]->frequency)
            {
                min2 = min1;
                min1 = i;
            }
            else if (leafNodes[i]->frequency < leafNodes[min2]->frequency)
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
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("文件打开失败!\n");
        return;
    }
    // 将编码后的字符串转换为二进制数据
    int len = strlen(encodedText);
    for (int i = 0; i < len; i += 8) // 8位一组
    {
        char byte = 0;
        for (int j = 0; j < 8 && i + j < len; j++)
        {
            byte = (byte << 1) | (encodedText[i + j] - '0');
        }
        fwrite(&byte, sizeof(char), 1, file);
    }

    fclose(file);
}
void printTree(Node *root, int level, int space)
{
    if (root == NULL)
        return;

    space += 3;

    printTree(root->right, level + 1, space);

    printf("\n");
    for (int i = 1; i < space; i++)
        printf(" ");

    printf("%d:%c\n", level, root->data);

    printTree(root->left, level + 1, space);
}
void printHuffmanCodesHelper(Node *root, char *code, int depth)
{
    if (root->left == NULL && root->right == NULL)
    {
        code[depth] = '\0';
        printf("%c: %s\n", root->data, code);
        return;
    }

    if (root->left != NULL)
    {
        code[depth] = '0';
        printHuffmanCodesHelper(root->left, code, depth + 1);
    }

    if (root->right != NULL)
    {
        code[depth] = '1';
        printHuffmanCodesHelper(root->right, code, depth + 1);
    }
}

void getHuffmanCodes(Node *root)
{
    char *code = (char *)malloc(256 * sizeof(char));
    printHuffmanCodesHelper(root, code, 0);
    free(code);
}

char *getHuffmanCode(Node *root, char ch, char *code)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == ch)
        {
            code[0] = '\0';
            return code;
        }
        else
        {
            return NULL;
        }
    }

    if (root->left != NULL)
    {
        code[0] = '0';
        char *result = getHuffmanCode(root->left, ch, code + 1);
        if (result != NULL)
            return result;
    }

    if (root->right != NULL)
    {
        code[0] = '1';
        char *result = getHuffmanCode(root->right, ch, code + 1);
        if (result != NULL)
            return result;
        printf("%s", result);
    }

    
    return NULL;
}

//解码
void decodeText(Node *root)
{
    FILE *codeFile = fopen("../CodeFile.txt", "r");
    FILE *decodeFile = fopen("../DecodeFile.txt", "w");
    if (codeFile == NULL || decodeFile == NULL)
    {
        printf("Failed to open the file.\n");
        exit(1);
    }

    Node *node = root;
    int c;
    while ((c = fgetc(codeFile)) != EOF)
    {
        if (c == '0')
        {
            node = node->left;
        }
        else if (c == '1')
        {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL)
        {
            fprintf(decodeFile, "%c", node->data);
            node = root;
        }
    }

    fclose(codeFile);
    fclose(decodeFile);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapChar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void sortFrequency(char data[], int frequency[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (frequency[j] < frequency[j + 1])
            {
                swap(&frequency[j], &frequency[j + 1]);
                swapChar(&data[j], &data[j + 1]);
            }
        }
    }
}

int main()
{
    char filename[] = "../SourceFile.txt";
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
            data[size] = i;
            frequency[size] = charFrequency[i];
            //printf("字符: %c  频率: %d\n", data[size], frequency[size]);
            size++;
        }
    }
    sortFrequency(data, frequency, size);
    for (int i = 0; i < size; i++)
    {
        printf("字符: %c  频率: %d\n", data[i], frequency[i]);
    }
    Node *root = buildHuffmanTree(data, frequency, size);
    printTree(root, 0,0);
    getHuffmanCodes(root);
    // 对正文进行编码并存入文件
    char encodedText[10000] = ""; // 用于存储编码后的文本
    FILE *inputFile = fopen("../SourceFile.txt", "r");
    if (inputFile == NULL)
    {
        printf("文件打开失败!\n");
        return 1;
    }
    decodeText(root);
    int i = 0;
    char code[100];
    while ((ch = fgetc(inputFile)) != EOF)
    {
        getHuffmanCode(root, ch, code);
        //printf("%d",i++);
        printf("%s\n", code);
        strcat(encodedText, code);
 //       printf("%s", encodedText);
    }
    //printf("%codes" );
    fclose(inputFile);
    // printf("%s", code);
     //printf("%s", encodedText);
     writeEncodedTextToFile("../CodeFile.txt", encodedText);
     return 0;
}
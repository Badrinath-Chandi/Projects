#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

typedef struct trieNode {
	char a;
	int isWord;
	int freq;
	trieNode* nodes[26];
}trieNode;

trieNode* createNode(char a) {
	trieNode* root = (trieNode*)malloc(sizeof(trieNode));
	root->a = a;
	root->isWord = 0;
	root->freq = 0;
	for (int i = 0; i < 26; i++)
		root->nodes[i] = NULL;
	return root;
}

void insertwordUtil(trieNode* node, char *word, int i,int len) {
	if (i>=len)
		return;
	if (node->nodes[word[i] - 97] == NULL) {
		node->nodes[word[i] - 97] = createNode(word[i]);
	}
	if (i == len - 1) {
		node->nodes[word[i] - 97]->isWord = true;
		node->nodes[word[i] - 97]->freq++;
	}
	insertwordUtil(node->nodes[word[i] - 97], word, i + 1, len);
}
void insertWord(trieNode* node,char *word)
{
	int len = strlen(word);
	insertwordUtil(node, word, 0,len);
}

bool searchWord(trieNode* node,char *word)
{
	trieNode* tmp = node;
	int len = strlen(word);
	int i = 0;
	while (tmp != NULL && i<len) {
		if (tmp->nodes[word[i] - 97] == NULL)
			break;
		tmp = tmp->nodes[word[i] - 97];
		i++;
	}
	if (i == len && tmp->isWord) {
		cout << "Frequency of occurance is " << tmp->freq << endl;
		return true;
	}
	return false;
}
int main()
{
	trieNode* root = createNode('?');
	insertWord(root, "badrinath");
	insertWord(root, "badrish");
	insertWord(root, "anjana");
	insertWord(root, "anusha");
	insertWord(root, "a");
	insertWord(root, "a");
	insertWord(root, "a");
	insertWord(root, "a");
	insertWord(root, "bad");
	insertWord(root, "is");
	insertWord(root, "important");
	if (searchWord(root, "badr"))
		cout << "badr Word is found " << endl;
	else
		cout << "badr word is not found" << endl;
	if (searchWord(root, "a"))
		cout << "a Word is found " << endl;
	else
		cout << "a word is not found" << endl;
	getchar();
}
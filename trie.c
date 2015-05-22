#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "trie.h"

struct trie_node *newTrieNode(void)
{
    struct trie_node *node = (struct trie_node *)malloc(sizeof(*node));
    if (!node) {
        fprintf(stderr, "***[%s]EMALLOC\n", __FUNCTION__);
        return NULL;
    }
    node->value = 0;
    for (int i = 0; i < NR_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void newTrie(struct trie *pTrie)
{
    pTrie->root = newTrieNode();
    pTrie->count = 0;
}

void insert(struct trie *pTrie, char key[])
{
    int level;
    int index;
    int length = strlen(key);
    
    pTrie->count++;
    struct trie_node *p = pTrie->root;
    
    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        if (!p->children[index]) {
            p->children[index] = newTrieNode();
        }
        p = p->children[index];
    }
    p->value = pTrie->count;
}

int search(struct trie *pTrie, char key[])
{
    int index;
    int level;
    int length = strlen(key);

    struct trie_node *p = pTrie->root;
    for (level = 0; level < length; level++) {
        index = CHAR_TO_INDEX(key[level]);
        
        if (!p->children[index]){
            return 0;
        }
        
        p = p->children[index];
    }
    return (!p && p->value);
}

int main(int argc, char **argv)
{
    struct trie Trie;
    char input[][8] = {"the","there","three","bye","eye","banana","bank","bad"};
    char output[][32] = {"Not present in Trie","present in Trie"};

    newTrie(&Trie);

    for (int i = 0; i < ARRAY_SIZE(input); i++)
        insert(&Trie, input[i]);

    fprintf(stderr, "%s-----%s\n","the",output[search(&Trie, "the")]);
    return 0;
}

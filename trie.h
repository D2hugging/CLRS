#ifndef __TRIE_H__
#define __TRIE_H__

#define NR_SIZE       26
#define CHAR_TO_INDEX(c)  ((int)c - (int)'a')
#define ARRAY_SIZE(a)       (sizeof(a)/sizeof(a[0]))
struct trie_node {
    int value;
    struct trie_node *children[NR_SIZE];
};

struct trie {
    struct trie_node *root;
    int count;
};

struct trie_node *newTrieNode(void);
void newTrie(struct trie *);
void insert(struct trie *, char key[]);
int search(struct trie *, char key[]);

#endif

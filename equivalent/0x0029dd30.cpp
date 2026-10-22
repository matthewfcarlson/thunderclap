// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 25/26, incomplete)
// FUN_0029dd30 @ 0x0029dd30
#include "compat/ptr.h"
struct Node {
    float key;
    int f4;
    int f8;
    float vx, vy, vz;
    int f18;
    Node *next;
};

struct Hdr {
    char pad0[0x14];
    int count;
};

struct Block {
    Hdr *hdr;
    Node *elems;
};

struct Sorter {
    Node *head;
    Node sentinel;
    int capacity;
};

class SortedMerge {
public:
    char pad00[0x28];
    char extra;
    char pad29[7];
    Block *blocks[4];
    char pad40[8];
    Sorter *sorter;
    hulk_freg FUN_0029dd30(Block *out);
};

hulk_freg SortedMerge::FUN_0029dd30(Block *out)
{
    hulk_freg sum = 0.0f;
    int n = out->hdr->count;
    sorter->head = &sorter->sentinel;
    sorter->capacity = n;

    Block *src[4];
    src[0] = blocks[0];
    src[1] = blocks[1];
    src[2] = blocks[2];
    src[3] = blocks[3];
    int numBlocks = 3 + (extra != 0);

    for (int b = 0; b < numBlocks; b++) {
        Block *blk = src[b];
        for (int j = blk->hdr->count - 1; j >= 0; j--) {
            Sorter *s = sorter;
            Node *cur = blk->elems + j;
            Node *prev = 0;
            Node *node = s->head;
            int i = 0;
            if (s->capacity > 0) {
                do {
                    if (cur->key > node->key) {
                        cur->next = node;
                        if (prev == 0)
                            s->head = cur;
                        else
                            prev->next = cur;
                        break;
                    }
                    i++;
                    prev = node;
                    node = node->next;
                } while (i < s->capacity);
            }
        }
    }

    Node *node = sorter->head;
    for (int k = 0; k < n; k++) {
        out->elems[k].f4 = node->f4;
        out->elems[k].vx = node->vx;
        out->elems[k].vy = node->vy;
        out->elems[k].vz = node->vz;
        out->elems[k].key = node->key;
        sum += node->key;
        node = node->next;
    }
    return sum;
}

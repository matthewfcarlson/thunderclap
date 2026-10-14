// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 12/14, incomplete)
// FUN_00279f80 @ 0x00279f80
struct Node { unsigned int parent; unsigned int left; unsigned int right; };
struct Tree_279f80 { unsigned int root; Node *nodes; };
// equiv-conv: FUN_00279f80 ecx stack stack stack stack stack
unsigned char FUN_00279f80(unsigned int end, const unsigned char *data, unsigned int position, unsigned int *offset, unsigned int *length, Tree_279f80 *tree)
{
    unsigned int current = tree->nodes[tree->root].right;
    unsigned int count = end - position;
    unsigned char aligned = 0;
    *length = 0;
    for (;;) {
        int difference = 0;
        unsigned int matched = 0;
        while (matched < count) {
            difference = (int)data[position + matched] - (int)data[current + matched];
            if (difference != 0) break;
            ++matched;
        }
        if (matched > *length) {
            unsigned int distance = position - current;
            if ((distance & 15) == 0) aligned = 1;
            else { *length = matched; *offset = distance; }
        }
        unsigned int *link = difference < 0 ? &tree->nodes[current].left : &tree->nodes[current].right;
        unsigned int next = *link;
        if (next != 0xffffffffU) { current = next; continue; }
        *link = position;
        tree->nodes[position].parent = current;
        tree->nodes[position].right = 0xffffffffU;
        tree->nodes[position].left = 0xffffffffU;
        return aligned;
    }
}

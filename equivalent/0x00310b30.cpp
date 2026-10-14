// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 12/14, incomplete)
// FUN_00310b30 @ 0x00310b30
struct Node {
    char pad00[8];
    int key;
    char pad0c[0x1c - 0xc];
    Node *next;
    bool FUN_00309b20(Node *other);
};

class Scanner {
public:
    char pad00[0x1fc];
    Node **nodes;
    char pad200[0x214 - 0x200];
    Node *first;
    Node *cursor;
    unsigned char active;
    void FUN_00310b30(Scanner *owner, int a, int b);
};

void Scanner::FUN_00310b30(Scanner *owner, int a, int b)
{
    if (a < 0)
        return;
    Node **table = nodes;
    first = table[a];
    if (owner != this)
        return;
    active = 1;
    Node *other = table[b];
    if (!other)
        return;
    if (first->key < other->key) {
        cursor = first;
    } else {
        cursor = other;
        other = first;
    }
    while (cursor) {
        if (cursor->FUN_00309b20(other))
            return;
        cursor = cursor->next;
    }
}

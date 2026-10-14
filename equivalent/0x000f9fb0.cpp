// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 19/20, incomplete)
// FUN_000f9fb0 @ 0x000f9fb0
extern unsigned __int64 DAT_004e0a08;
extern unsigned __int64 DAT_004e0a10;

class Node {
public:
    virtual void v0();
    virtual unsigned __int64 Kind();
    Node *next;
};

class NodeList {
public:
    char pad0[8];
    Node *cur;
    int f0c;
    int depth;
    void FUN_000f9fb0();
};

void NodeList::FUN_000f9fb0()
{
    Node *n = cur;
    if (n == 0)
        return;
    int level = 0;
    while (level >= 0) {
        n = n->next;
        if (n == 0)
            return;
        if (n->Kind() == DAT_004e0a08)
            level++;
        else if (n->Kind() == DAT_004e0a10)
            level--;
    }
    if (n != 0 && n->Kind() == DAT_004e0a10) {
        depth--;
        cur = n;
    }
}

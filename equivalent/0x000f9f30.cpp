// STATUS: equivalent (tools/equiv.py level 3: 1911 inputs, branch coverage 22/22)
// FUN_000f9f30 @ 0x000f9f30
class Node {
public:
    virtual void v0();
    virtual unsigned __int64 Key();
    Node* next;
    int depth;
};

extern unsigned __int64 DAT_004e0a08;

struct Chain {
    char pad0[8];
    Node* head;
    int pad0c;
    int count;
    void FUN_000f9f30();
};

void Chain::FUN_000f9f30() {
    if (head == 0)
        return;
    Node* n = head->next;
    if (n == 0)
        return;
    while (n->depth > 1) {
        n = n->next;
        if (n == 0)
            return;
    }
    if (n->Key() != DAT_004e0a08)
        return;
    Node* m = head->next;
    if (m == 0)
        return;
    while (m->depth > 1) {
        m = m->next;
        if (m == 0)
            return;
    }
    if (m->Key() != DAT_004e0a08)
        return;
    count++;
    head = m;
}

struct Node {
    Node* next; // 0
    char kind;  // 4
    char sub;   // 5
    char pad6[10];
    Node* owner; // 0x10
    int f14;
    char pad18[4];
    int f1c;
    int f20;
    char pad24[4];
    int f28;
    short s2c;
    short s2e;
    char c30;
    char c31;
    char c32;
    char pad33;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    char pad4c[4];
    int f50;
    int f54;
};
Node* Alloc(Node* a, int b, int c, int size);
void Init();
Node* Target(Node* p) {
    Node* n = Alloc(p, 0, 0, 0x58);
    n->next = p->next;
    Node* o = p->owner;
    p->next = n;
    n->owner = o;
    n->kind = 8;
    n->sub = *((char*)o + 0x14);
    n->f1c = 0;
    n->f20 = 0;
    n->f50 = 0;
    n->f3c = 0;
    n->c30 = 0;
    n->f34 = 0;
    n->c31 = 1;
    n->f38 = 0;
    n->f48 = 0;
    n->s2c = 0;
    n->s2e = 0;
    n->c32 = 0;
    n->f14 = 0;
    n->f28 = 0;
    n->f54 = 0;
    n->f40 = 0;
    Init();
    n->f40 = p->f40;
    n->f44 = p->f44;
    return n;
}

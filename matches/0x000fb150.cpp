struct Node {
    int a;
    int b;
    int state;
};
struct Obj {
    char pad0[8];
    Node* root;
    Node* cur;
    char pad10[4];
    char done;
    int next();
};
int Obj::next() {
    Node* n = root;
    if (!n)
        return 0;
    int r;
    if (done != 1) {
        Node* c = cur;
        if (!c) {
            c = *(Node**)((char*)n + 4);
        } else {
            c = *(Node**)((char*)c + 4);
        }
        r = (int)c;
        if (c && c->state < 2)
            r = 0;
    } else
        r = 0;
    cur = (Node*)r;
    if (!r)
        done = 1;
    return r;
}

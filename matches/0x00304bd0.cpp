struct Node;
struct Vec_304bd0 {
    Node** b;
    Node** e;
    int bytes() { return (char*)e - (char*)b; }
    unsigned size() { return e - b; }
};
struct Node {
    char p0[8];
    int level;
    char p1[8];
    Vec_304bd0* kids;
    char flag;
    Node* child(unsigned i) { return kids->b[i]; }
    unsigned count() { return kids->size(); }
};
struct Mgr_304bd0 {
    void Fn(Node* n, int lvl, int f);
};
void Mgr_304bd0::Fn(Node* n, int lvl, int f) {
    if (lvl == n->level)
        n->flag = (char)f;
    if (lvl >= n->level && n->kids && (n->kids->bytes() & 0xfffffffc) != 0) {
        for (unsigned i = 0; i < n->count(); i++)
            Fn(n->child(i), lvl, f);
    }
}

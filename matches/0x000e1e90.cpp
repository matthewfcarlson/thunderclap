struct V {
    float x, y, z;
};
struct Sub {
    void Get(V* out);
};
struct Node {
    char pad[0x18];
    Sub sub;
};
struct Handle {
    Node* p;
};
int Cmp(Handle* a, Handle* b) {
    Node* na = a->p;
    Node* nb = b->p;
    if (!na)
        return nb != 0;
    if (!nb)
        return -1;
    V va, vb;
    na->sub.Get(&va);
    nb->sub.Get(&vb);
    int r = 0;
    if (va.z != vb.z) {
        if (va.z > vb.z)
            r = -1;
        else
            r = 1;
    }
    return r;
}

struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void F(int a, unsigned m, int b, int c);
    char pad[0xc];
    int flags;
    Node* parent;
};
void Node::F(int a, unsigned m, int b, int c) {
    if (b == 1 && parent) {
        if ((char)a == 1) {
            if ((char)c == 1) {
                if ((flags & m) == m)
                    return;
            }
        } else if ((char)c == 1) {
            if ((flags & ~m) == m)
                return;
        }
        parent->F(a, m, 1, c);
    }
    if ((char)a == 1) {
        flags |= m;
        return;
    }
    flags &= ~m;
}

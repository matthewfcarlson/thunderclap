void* Alloc(int n);
struct Node {
    Node* Init_001d4320(int a, int b, int c);
    void Set(int a);
};
struct Q {
    void Add(Node* n);
};
struct Mgr {};
void Reg(Mgr*, Node*);
void Cb(Mgr*, void (*)(), int);
void Post(Mgr*, int, int);
void Handler();
struct Owner {
    char pad[8];
    Mgr* mgr;
    Q q;
    void Fn(int a, int b, int c);
};
void Owner::Fn(int a, int b, int c) {
    Node* p = (Node*)Alloc(0x24);
    Node* n;
    if (p)
        n = p->Init_001d4320(a, b, c);
    else
        n = 0;
    n->Set(a);
    q.Add(n);
    Mgr* m = mgr;
    Reg(m, n);
    Cb(m, (void (*)())Handler, 1);
    Post(m, -10001, a);
}

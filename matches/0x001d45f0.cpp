struct Obj;
void* __cdecl Alloc(int n);
struct Node {
    Node* Init(int a, int b, int c);
    void Setup(int a);
};
struct List {
    void Add(Node* n);
};
void __cdecl FnA(int a, Node* n);
void __cdecl FnB(int a, void* f, int c);
void __cdecl FnC(int a, int b, int c);
void Cb();

struct Owner {
    int pad0;
    int pad1;
    int mHandle;
    List mList;
    void Create(int a, int b, int c);
};

void Owner::Create(int a, int b, int c) {
    Node* mem = (Node*)Alloc(0x24);
    Node* n;
    if (mem) {
        n = mem->Init(a, b, c);
    } else {
        n = 0;
    }
    n->Setup(a);
    mList.Add(n);
    int h = mHandle;
    FnA(h, n);
    FnB(h, (void*)Cb, 1);
    FnC(h, -10001, a);
}

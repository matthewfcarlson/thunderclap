typedef unsigned __int64 U64;

struct Node;

struct Iter {
    __int64 state;      // 8-byte local (forces the original's 8-byte stack alignment)
    void FUN_002314a0(void* head);
    Node* FUN_00231640();
    U64 FUN_00231530();
    Node* FUN_002314c0();
};

struct Source {
    char pad[0xc];
    void* head;
};

class Listener {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void OnEntry(U64 id, Node* node);
    void FUN_00266220(Source* src);
};

void Listener::FUN_00266220(Source* src)
{
    Iter it;
    it.FUN_002314a0(src->head);
    Node* n = it.FUN_00231640();
    if (n) {
        do {
            OnEntry(it.FUN_00231530(), n);
            n = it.FUN_002314c0();
        } while (n);
    }
}

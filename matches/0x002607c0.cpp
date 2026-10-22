extern "C" void _ReadWriteBarrier();
struct Node {
    Node* next;
};
bool __cdecl Read(unsigned a, unsigned* out);
char* __cdecl Alloc(unsigned a);
struct SeqEventContainer_2607c0 {
    virtual bool v0(unsigned a);
    int m4, m8;
    Node* mc;
    Node* m10;
};
bool SeqEventContainer_2607c0::v0(unsigned a) {
    unsigned n;
    if (!Read(a, &n))
        return false;
    unsigned i = 0;
    if (n > 0) {
        do {
            char* p = Alloc(a);
            if (!p)
                return false;
            Node* nd = (Node*)(p + 4);
            nd->next = 0;
            if (m10 == 0)
                mc = nd;
            else
                m10->next = nd;
            m10 = nd;
            _ReadWriteBarrier();
            m8++;
            i++;
        } while (i < n);
    }
    return true;
}

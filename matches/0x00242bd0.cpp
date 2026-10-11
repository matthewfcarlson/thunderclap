extern "C" void _ReadWriteBarrier();
extern char gPool[];
extern void* __cdecl FUN_00247530(void*);
struct Node {
    int a[10];
};
Node* __cdecl FUN_00242bd0() {
    Node* p = (Node*)FUN_00247530(gPool);
    if (p) {
        int* q = (int*)p + 1;
        q[0] = (int)q;
        ((int*)p)[2] = (int)q;
        ((int*)p)[3] = (int)q;
        ((int*)p)[0] = (int)q;
        ((int*)p)[4] = 0;
        _ReadWriteBarrier();
        int* r = (int*)p + 6;
        r[0] = (int)r;
        ((int*)p)[7] = (int)r;
        ((int*)p)[8] = (int)r;
        ((int*)p)[9] = 0;
        ((int*)p)[5] = (int)r;
        return p;
    }
    return 0;
}

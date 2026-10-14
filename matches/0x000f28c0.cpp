// Same code shape as 0x000f2740 (propagated; names are from that function)
typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct X_f28c0 {
    int make(void*, void*);
};
struct Y_f28c0 {
    int pad;
    void* field;
    void* slots[32];
    int f(void*);
};
int Y_f28c0::f(void* p) {
    if (!field)
        return 0;
    X_f28c0* x = (X_f28c0*)FUN_0008d690(0x60);
    int r = x ? x->make(field, p) : 0;
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (r)
                slots[i] = (void*)r;
            return r;
        }
        ++i;
    } while (i < 32);
    return r;
}

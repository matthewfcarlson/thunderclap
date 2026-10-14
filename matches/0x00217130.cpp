struct Inner_217130 {
    char pad14[0x14];
    unsigned char value;
    char pad15[3];
    void* link;
};
struct Outer_217130 {
    char pad10[0x10];
    Inner_217130* p;
};
void FUN_00217130(Outer_217130* a, unsigned char* b, unsigned char c) {
    Inner_217130* x = a->p;
    *(void**)b = x->link;
    x->link = b;
    b[5] = x->value;
    b[4] = c;
}
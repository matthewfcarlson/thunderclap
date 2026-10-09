struct Inner {
    void A(int, int, void*);
    void B(int, int, int, int, void*);
};
struct Obj {
    char pad0[0x40];
    char field40[0x58];
    int index;
    int value9c;
    char padA0[4];
    unsigned char flag;
    char padA5[3];
    Inner inner;
    char padB0[0x128];
    int* items;
    void target(int arg);
};
void Obj::target(int arg) {
    if (!flag)
        inner.A(arg, items[index], (char*)this + 0x40);
    else {
        int* q = items + index;
        inner.B(arg, q[0], q[1], value9c, (char*)this + 0x40);
    }
}
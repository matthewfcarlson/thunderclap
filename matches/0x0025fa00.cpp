struct Pair {
    int a;
    int b;
};
struct MetaType {
    int vptr;
    char pad04[0x10];
    int* m14;
    int* m18;
    int* m1c;
    int* m20;
    int m24;
    int pad28;
    Pair key;
    MetaType* Init(int, int);
};
extern void Register(int*, MetaType*, Pair*);
MetaType* MetaType::Init(int a, int b) {
    int* p = (int*)((char*)this + 0x18);
    vptr = 0x42aa40;
    *p = (int)p;
    m1c = p;
    m20 = p;
    m14 = p;
    m24 = 0;
    Pair* k = &key;
    k->a = a;
    key.b = b;
    if (*(int*)0x4e79cc == 0) {
        *(int*)0x4e79bc = 0x4e79bc;
        *(int*)0x4e79c0 = 0x4e79bc;
        *(int*)0x4e79c4 = 0x4e79bc;
        *(int*)0x4e79c8 = 0;
        *(int*)0x4e79b8 = 0x4e79bc;
    }
    Register(*(int**)0x4cd360, this, k);
    ++*(int*)0x4e79cc;
    return this;
}
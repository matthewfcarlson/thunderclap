extern "C" char DAT_0042aa40[];
extern "C" char DAT_004cd360[];
extern "C" char DAT_004e79b8[];
extern "C" char DAT_004e79bc[];
extern "C" char DAT_004e79c0[];
extern "C" char DAT_004e79c4[];
extern "C" char DAT_004e79c8[];
extern "C" char DAT_004e79cc[];
struct Pair_25fa00 {
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
    Pair_25fa00 key;
    MetaType* Init(int, int);
};
extern void Register(int*, MetaType*, Pair_25fa00*);
MetaType* MetaType::Init(int a, int b) {
    int* p = (int*)((char*)this + 0x18);
    vptr = ((int)DAT_0042aa40);
    *p = (int)p;
    m1c = p;
    m20 = p;
    m14 = p;
    m24 = 0;
    Pair_25fa00* k = &key;
    k->a = a;
    key.b = b;
    if (*(int*)((int)DAT_004e79cc) == 0) {
        *(int*)((int)DAT_004e79bc) = ((int)DAT_004e79bc);
        *(int*)((int)DAT_004e79c0) = ((int)DAT_004e79bc);
        *(int*)((int)DAT_004e79c4) = ((int)DAT_004e79bc);
        *(int*)((int)DAT_004e79c8) = 0;
        *(int*)((int)DAT_004e79b8) = ((int)DAT_004e79bc);
    }
    Register(*(int**)((int)DAT_004cd360), this, k);
    ++*(int*)((int)DAT_004e79cc);
    return this;
}
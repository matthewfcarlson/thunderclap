struct V3_2837e0 {
    int a, b, c;
};
struct Inner_2837e0 {
    void Fn(int a, int b, int c, int d, int e, int f, int g, int h, V3_2837e0 v, int i, int j, int k);
};
struct Obj_2837e0 {
    char pad0[0x48];
    char* mArr;
    char pad1[0xc];
    unsigned mCount;
    char* mInfo;
    unsigned Run(int a, int b, int c, int d, int e, int f, int g, int h, V3_2837e0 v, int i, int j, int k);
};

unsigned Obj_2837e0::Run(int a, int b, int c, int d, int e, int f, int g, int h, V3_2837e0 v, int i, int j, int k) {
    unsigned n = mCount;
    unsigned idx = n % 6;
    ((Inner_2837e0*)(*(char**)(mArr + idx * 16)))->Fn(a, b, c, d, e, f, g, h, v, i, j, k);
    *(unsigned*)(mInfo + idx * 8) = n;
    *(char*)(mInfo + idx * 8 + 4) = 1;
    mCount++;
    return n;
}

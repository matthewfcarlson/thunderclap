extern int vt;
class PrimBuf {
public:
    PrimBuf(int arg);
    void InitBase();
    int p0, p4, p8;
    int m0c;
    int p10, p14;
    int m18, m1c, m20, m24, m28, m2c, m30;
    unsigned char b34, b35, b36;
    int m38;
};

PrimBuf::PrimBuf(int arg) {
    InitBase();
    m18 = 0; m1c = 0; m20 = 0; m24 = 0; m28 = 0; m2c = 0; m30 = 0;
    b34 = 0; b35 = 0; b36 = 0;
    m38 = arg;
    *(int*)this = (int)&vt;
    m0c = *(int*)(*(int*)((char*)arg + 0x154) + 0x10);
}

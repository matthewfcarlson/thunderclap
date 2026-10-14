// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 8/8)
// FUN_002c03e0 @ 0x002c03e0
class Source {
  public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual unsigned int Get(int x, int y);
};
// equiv-conv: FUN_002c03e0 eax ecx edx stack stack stack stack
void FUN_002c03e0(int width, int height, int stride, Source* src, unsigned int* dst, int x0, int y0) {
    for (int y = y0; y < y0 + height; y++) {
        unsigned int* p = dst;
        for (int x = x0; x < x0 + width; x++) {
            *p = src->Get(x, y);
            p++;
        }
        dst += stride;
    }
}

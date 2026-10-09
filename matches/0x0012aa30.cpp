// Same code shape as 0x0012a410 (propagated; names are from that function)
extern "C" void* __cdecl alloc(unsigned int);
extern int tdcVtable;
class TDC {
  public:
    int vf;
    char pad[8];
    int x;
    int y;
    unsigned char a;
    unsigned char b;
    void init(int);
};
TDC* __cdecl target() {
    TDC* p = (TDC*)alloc(0x18);
    int z = 0;
    if (p) {
        p->init(z);
        p->x = z;
        p->y = z;
        p->a = (unsigned char)z;
        p->b = (unsigned char)z;
        p->vf = (int)&tdcVtable;
        return p;
    }
    return 0;
}

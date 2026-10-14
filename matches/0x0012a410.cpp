extern "C" void* __cdecl alloc(unsigned int);
extern int tdcVtable;
class TDC_12a410 {
  public:
    int vf;
    char pad[8];
    int x;
    int y;
    unsigned char a;
    unsigned char b;
    void init(int);
};
TDC_12a410* __cdecl target() {
    TDC_12a410* p = (TDC_12a410*)alloc(0x18);
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

extern void* g_vftable[];
void* Alloc(int);
class Obj {
  public:
    void* vptr;
    int m4, m8, mc, m10;
    char m14;
    int* m18;
    int* m1c;
    int* m20;
    int* m24;
    Obj();
};
Obj::Obj() {
    vptr = g_vftable;
    int* q = &m4;
    *q = 0;
    int** pp = &m18;
    pp[0] = 0;
    pp[1] = 0;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 1;
    int* p = (int*)Alloc(0x80);
    m18 = p;
    if (p) {
        m1c = p;
        m20 = p;
        m24 = p + 0x20;
        return;
    }
    m1c = 0;
}

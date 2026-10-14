extern void* g_vftable_dc600[];
void Free(void*) throw();
class Base_dc600 {
  public:
    void* vptr;
    void Fin();
};
class Obj_dc600 : public Base_dc600 {
  public:
    char p[0x14c];
    int n;
    void* m154;
    void* m158;
    void* m15c;
    void* m160;
    void** a;
    void** b;
    void* m16c;
    ~Obj_dc600() throw();
};
Obj_dc600::~Obj_dc600() throw() {
    vptr = g_vftable_dc600;
    if (m158) {
        Free(m158);
        m158 = 0;
    }
    if (m15c) {
        Free(m15c);
        m15c = 0;
    }
    if (m160) {
        Free(m160);
        m160 = 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            Free(a[i]);
            a[i] = 0;
        }
        if (b[i]) {
            Free(b[i]);
            b[i] = 0;
        }
    }
    if (a) {
        Free(a);
        a = 0;
    }
    if (b) {
        Free(b);
        b = 0;
    }
    if (m16c) {
        Free(m16c);
        m16c = 0;
    }
    Fin();
}

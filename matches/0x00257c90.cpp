extern void* g_vftable[];
extern char g_pool[];
void F1(void*);
void F2(void*);
void Release2(void*, void*);
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x24];
    struct SB {
        char* p;
        char b[0x10];
        void Reset() { p = b; }
    } sb;
    char m3c[8];
    char m44[8];
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;
    sb.Reset();
    F1(m3c);
    F2(m44);
    Fin();
    if (flags & 1)
        Release2(g_pool, this);
    return this;
}

extern void* g_vftable_257c90[];
extern char g_pool_257c90[];
void F1(void*);
void F2(void*);
void Release2(void*, void*);
class Entity_257c90 {
  public:
    void* vptr;
    void Fin();
};
class Sequence_257c90 : public Entity_257c90 {
  public:
    char pad[0x24];
    struct SB {
        char* p;
        char b[0x10];
        void Reset() { p = b; }
    } sb;
    char m3c[8];
    char m44[8];
    Sequence_257c90* f2(unsigned char flags);
};
Sequence_257c90* Sequence_257c90::f2(unsigned char flags) {
    vptr = g_vftable_257c90;
    sb.Reset();
    F1(m3c);
    F2(m44);
    Fin();
    if (flags & 1)
        Release2(g_pool_257c90, this);
    return this;
}

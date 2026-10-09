typedef unsigned char u8;
struct Sub {
    void Setup(const char* s);
    char pad[8];
    u8 flags;
    char p2[3];
    unsigned int bits;
    unsigned int zero;
};
class Stream {
  public:
    int vf;
    void BaseInit();
    char pad[4];
    Sub sub;
};
extern void* Alloc(void*);
extern int gPool;
class Type {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Stream* vfunc_3();
};
Stream* Type::vfunc_3() {
    Stream* p = (Stream*)Alloc(&gPool);
    if (p) {
        p->BaseInit();
        Sub* s = &p->sub;
        p->vf = 0x42a2b0;
        s->Setup("MyRsdFile");
        s->flags &= 0xfe;
        s->bits &= 0x80000000;
        s->zero = 0;
        return p;
    }
    return 0;
}

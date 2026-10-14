extern "C" void* __cdecl alloc(void*);
extern char pool_2562c0;
class Part {
  public:
    char pad[8];
    unsigned char flags;
    char pad2[3];
    unsigned int bits;
    int extra;
    void init(const char*);
    Part(unsigned char* flag) {
        *flag = 0;
        init("MyRsdFile");
        flags &= 0xfe;
        bits &= 0x80000000;
        extra = 0;
    }
};
class Base_2562c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[4];
    Base_2562c0();
};
class Clip : public Base_2562c0 {
  public:
    unsigned char flag;
    char pad[7];
    Part part;
    Clip() : Base_2562c0(), part(&flag) {}
};
class ClipType {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Clip* f3();
};
Clip* ClipType::f3() {
    void* p = alloc(&pool_2562c0);
    if (p) {
        Clip* q = (Clip*)p;
        q->Clip::Clip();
        return q;
    }
    return 0;
}
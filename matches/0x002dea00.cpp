typedef unsigned int u32_2dea00;
void* alloc(u32_2dea00);
class Init_2dea00 {
  public:
    void* run();
};
class ImageConverter {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* f4(void*);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(void*, void*);
    void* vfunc_4(void* p);
};
void* ImageConverter::vfunc_4(void* p) {
    int t = (int)alloc(0x30);
    void* x;
    if (t) {
        x = ((Init_2dea00*)t)->run();
    } else
        x = 0;
    struct Pair {
        int a;
        int b;
    }* q = (Pair*)p;
    class Obj {
      public:
        virtual void a();
        virtual void b();
        virtual void c();
        virtual void d();
        virtual void e();
        virtual void g(void*, void*);
    };
    ((Obj*)x)->g((void*)q->a, (void*)q->b);
    f8(p, x);
    return x;
}
class ImageConverter {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(void** items, int count, void* a, void* b);
    virtual void f4();
    virtual void f5();
    virtual void f6(void* item, int n, int i);
    virtual void f7();
    virtual void f8();
};
class Other_2de390 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual int n(void*, int);
    virtual void o(void*);
};
int ImageConverter::f3(void** items, int count, void* a, void* b) {
    Other_2de390* obj = *(Other_2de390**)((char*)a + 0x10);
    int n = obj->n(b, 0);
    for (int i = 0; i < count; ++i)
        f6(items[i], n, i);
    obj->o(b);
    return (int)a;
}

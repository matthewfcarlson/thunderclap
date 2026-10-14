struct Data_293d00 {
    int a, b, c;
};
extern Data_293d00 gData_293d00;
extern int gA_293d00, gB, gC;
struct InitObj_293d00 {
    void foo();
};
extern InitObj_293d00 gInit_293d00;
class Host_293d00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17(int, Data_293d00*);
};
class Owner_293d00 {
  public:
    Host_293d00* host;
    void run(Data_293d00* p);
};
void Owner_293d00::run(Data_293d00* p) {
    gInit_293d00.foo();
    gA_293d00 = p->a;
    gB = p->b;
    gC = p->c;
    host->f17(0, &gData_293d00);
}
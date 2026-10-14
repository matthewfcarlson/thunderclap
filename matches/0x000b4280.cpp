class A_b4280 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(void*, int);
};
class B_b4280 {
  public:
    char pad[0x10];
    A_b4280* p;
};
void __fastcall target(B_b4280* self, void*, void* first, void* arg) {
    int x = arg ? *(int*)((char*)arg + 0x10) : 0;
    self->p->f5(first, x);
}
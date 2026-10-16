class Base {
  public:
    virtual int Test(void*);
    virtual void v1();
};
class Derived : public Base {
  public:
    virtual int Test(void*);
    virtual void v1();
};
extern int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
int Derived::Test(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
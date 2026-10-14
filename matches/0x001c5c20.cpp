class Provider_1c5c20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int Get();
};
class Builder {
  public:
    void* Create(int, int);
};
class Result_1c5c20 {
  public:
    void Finish(int);
};
class Owner_1c5c20 {
  public:
    char pad[8];
    Provider_1c5c20* provider;
    int value;
    void* Run(int);
};
extern void* Alloc(unsigned int);
void* Owner_1c5c20::Run(int arg) {
    int n = provider->Get();
    void* p = Alloc(0xb0);
    void* r;
    if (p)
        r = ((Builder*)p)->Create(arg, n);
    else
        r = 0;
    ((Result_1c5c20*)r)->Finish(value);
    return r;
}
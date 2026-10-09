class Result {
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
    virtual float Get();
};
class Owner {
  public:
    float Probe(unsigned int arg);
    Result* Find(unsigned long long key);
};
extern unsigned long long FUN_0027b020(unsigned int);
extern const float zero;
extern const float scale;
float Owner::Probe(unsigned int arg) {
    unsigned long long k = FUN_0027b020(arg);
    Result* r = Find(k);
    if (!r)
        return zero;
    return r->Get() * scale;
}

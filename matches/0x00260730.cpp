struct Pair_260730 {
    int a;
    int b;
};
class Result_260730 {
  public:
    virtual char Check(int);
    virtual void V1();
    virtual void V2();
    virtual Result_260730* Get();
    virtual void Stop(int);
};
extern "C" char Parse(int, Pair_260730*);
extern "C" Result_260730* Find(Pair_260730*);
extern "C" void * FUN_00260730(int param) {
    Pair_260730 p;
    p.a = 0;
    p.b = 0;
    if (!Parse(param, &p))
        return (Result_260730 *)0;
    Result_260730* r = Find(&p);
    if (!r)
        return (Result_260730 *)0;
    r = r->Get();
    if (!r->Check(param)) {
        r->Stop(1);
        return (Result_260730 *)0;
    }
    return (Result_260730 *)r;
}
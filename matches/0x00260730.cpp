struct Pair {
    int a;
    int b;
};
class Result {
  public:
    virtual char Check(int);
    virtual void V1();
    virtual void V2();
    virtual Result* Get();
    virtual void Stop(int);
};
extern "C" char Parse(int, Pair*);
extern "C" Result* Find(Pair*);
Result* FUN_00260730(int param) {
    Pair p;
    p.a = 0;
    p.b = 0;
    if (!Parse(param, &p))
        return 0;
    Result* r = Find(&p);
    if (!r)
        return 0;
    r = r->Get();
    if (!r->Check(param)) {
        r->Stop(1);
        return 0;
    }
    return r;
}
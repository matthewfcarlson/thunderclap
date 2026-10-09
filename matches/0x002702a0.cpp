extern "C" int Alloc(int, int);
extern "C" int gValue;
class Obj {
  public:
    virtual void Finish();
    void Init(int, int, int, int, int, int, int);
};
class Factory {
  public:
    Obj* Create();
};
void Target(Obj** out, int a, int b, int c, int d, int e, int f) {
    gValue = d;
    Factory* p = (Factory*)Alloc(d, 0x34);
    Obj* obj;
    if (p)
        obj = p->Create();
    else
        obj = 0;
    obj->Init(0, a, b, c, d, e, f);
    obj->Finish();
    *out = obj;
}

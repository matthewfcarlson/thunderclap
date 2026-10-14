extern "C" int Alloc(int, int);
extern "C" int gValue_2702a0;
class Obj_2702a0 {
  public:
    virtual void Finish();
    void Init(int, int, int, int, int, int, int);
};
class Factory_2702a0 {
  public:
    Obj_2702a0* Create();
};
void Target(Obj_2702a0** out, int a, int b, int c, int d, int e, int f) {
    gValue_2702a0 = d;
    Factory_2702a0* p = (Factory_2702a0*)Alloc(d, 0x34);
    Obj_2702a0* obj;
    if (p)
        obj = p->Create();
    else
        obj = 0;
    obj->Init(0, a, b, c, d, e, f);
    obj->Finish();
    *out = obj;
}

class Check {
  public:
    int Ready();
};
class Inner {
  public:
    void Init(int);
    char pad[0x4c];
};
class Res {
  public:
    void Scale(float);
};
class Obj {
  public:
    char p0[0x10];
    Check* thing;
    char p14[0xc8];
    Inner inner;
    Res* res;
    void Finish(int, float);
    void Do(int, float);
};
void Obj::Do(int a, float b) {
    inner.Init(0);
    if (thing->Ready()) {
        if (res)
            res->Scale(b * 1000.0f);
        Finish(a, b);
    }
}

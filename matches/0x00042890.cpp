class Check_42890 {
  public:
    int Ready();
};
class Inner_42890 {
  public:
    void Init(int);
    char pad[0x4c];
};
class Res_42890 {
  public:
    void Scale(float);
};
class Obj_42890 {
  public:
    char p0[0x10];
    Check_42890* thing;
    char p14[0xc8];
    Inner_42890 inner;
    Res_42890* res;
    void Finish(int, float);
    void Do(int, float);
};
void Obj_42890::Do(int a, float b) {
    inner.Init(0);
    if (thing->Ready()) {
        if (res)
            res->Scale(b * 1000.0f);
        Finish(a, b);
    }
}

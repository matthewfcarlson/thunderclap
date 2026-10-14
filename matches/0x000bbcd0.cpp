class Sub {
  public:
    void Fn(int a);
};
class Mgr {
  public:
    char pad[0x3c];
    Sub* sub;
    void Fn(int a);
};
class Obj {
  public:
    char pad[4];
    Mgr* mgr;
    void Fn(int a);
};
void Obj::Fn(int a) {
    Mgr* m = mgr;
    if (m->sub)
        m->sub->Fn(a);
}

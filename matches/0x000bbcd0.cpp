class Sub_bbcd0 {
  public:
    void Fn(int a);
};
class Mgr_bbcd0 {
  public:
    char pad[0x3c];
    Sub_bbcd0* sub;
    void Fn(int a);
};
class Obj_bbcd0 {
  public:
    char pad[4];
    Mgr_bbcd0* mgr;
    void Fn(int a);
};
void Obj_bbcd0::Fn(int a) {
    Mgr_bbcd0* m = mgr;
    if (m->sub)
        m->sub->Fn(a);
}

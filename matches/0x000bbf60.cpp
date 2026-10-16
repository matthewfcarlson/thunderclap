class Obj {
  public:
    void Do(int);
};
class Wrap {
  public:
    char pad[4];
    Obj* p;
    void Fn(int);
};
void Wrap::Fn(int x) {
    if (p)
        p->Do(x);
}
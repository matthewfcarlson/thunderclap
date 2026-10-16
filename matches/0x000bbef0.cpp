class Child {
  public:
    void Fn();
};
class Thing {
  public:
    char pad[4];
    Child* p;
    void Fn(int);
};
void Thing::Fn(int unused) {
    if (p)
        p->Fn();
}
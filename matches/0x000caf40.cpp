class Obj {
  public:
    void Call(int);
};

class Target {
  public:
    void Fn(int);
    char pad[0x88];
    Obj* mObj;
};

void Target::Fn(int x) {
    Obj* p = mObj;
    if (p)
        p->Call(x);
}

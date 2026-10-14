class Sub {
  public:
    void Fn(int x);
};

class Obj {
  public:
    char pad[0x88];
    Sub* m88;
    void Target(int x);
};

void Obj::Target(int x) {
    Sub* p = m88;
    if (p)
        p->Fn(x);
}

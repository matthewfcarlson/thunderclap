class Sub {
  public:
    void A();
    void Fn();
};

class Obj {
  public:
    char pad[0x88];
    Sub* m;
    void Target();
};

void Obj::Target() {
    if (m)
        m->A();
}

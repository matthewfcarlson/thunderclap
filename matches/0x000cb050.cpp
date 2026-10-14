class Sub_cb050 {
  public:
    void A();
    void Fn();
};

class Obj_cb050 {
  public:
    char pad[0x88];
    Sub_cb050* m;
    void Target();
};

void Obj_cb050::Target() {
    if (m)
        m->A();
}

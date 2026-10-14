class Sub_cb260 {
  public:
    void Fn(int x);
};

class Obj_cb260 {
  public:
    char pad[0x88];
    Sub_cb260* m88;
    void Target(int x);
};

void Obj_cb260::Target(int x) {
    Sub_cb260* p = m88;
    if (p)
        p->Fn(x);
}

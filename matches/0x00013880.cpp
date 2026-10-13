class Sub {
  public:
    void Fn();
};

class Obj {
  public:
    char pad[0x18];
    Sub sub;
    void Target();
};

void Obj::Target() {
    sub.Fn();
}

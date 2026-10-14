class Sub_13880 {
  public:
    void Fn();
};

class Obj_13880 {
  public:
    char pad[0x18];
    Sub_13880 sub;
    void Target();
};

void Obj_13880::Target() {
    sub.Fn();
}

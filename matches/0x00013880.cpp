class Sub_13880 {
  public:
    void Fn(int);
};

class Obj_13880 {
  public:
    char pad[0x18];
    Sub_13880 sub;
    void Target(int);
};

void Obj_13880::Target(int a0) {
    sub.Fn(a0);
}

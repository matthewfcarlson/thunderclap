class Sub_272880 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_272880 {
  public:
    char pad[0x0c];
    Sub_272880 sub;
    char pad2[0xa4];
    int value;
    int Run();
};
int Obj_272880::Run() {
    sub.A();
    int v = value;
    sub.B();
    return v;
}
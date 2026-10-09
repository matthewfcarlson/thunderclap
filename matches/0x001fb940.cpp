class Obj {
  public:
    char pad[0xcd];
    unsigned char a;
    char gap;
    unsigned char b;
    void f();
};
void Obj::f() {
    b = a;
}
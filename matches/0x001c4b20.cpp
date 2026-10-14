class Target_1c4b20 {
  public:
    char pad0[0x80];
    int a80;
    int a84;
    int a88;
    char pad8c[0x20];
    int aac;
    void f();
};
void Target_1c4b20::f() {
    a80 = a84;
    a88 = 0;
    ++aac;
}
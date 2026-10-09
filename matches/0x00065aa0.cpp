class Target {
    char pad[0x36c];
    unsigned char field;

  public:
    void f();
};
void Target::f() {
    field = 0;
}
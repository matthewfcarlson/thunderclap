class A_88e40 {
  public:
    char pad[0x9c];
    char flag;
    void* f();
};
void* A_88e40::f() {
    if (flag)
        return (char*)this + 0x5c;
    return 0;
}
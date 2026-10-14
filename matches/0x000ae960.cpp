class C_ae960 {
  public:
    virtual void v();
    char* ptr;
    int f();
};
int C_ae960::f() {
    char* q = ptr + 0x134;
    int x = -1;
    if (q[0])
        x = (signed char)q[4] - 0x30;
    return x;
}
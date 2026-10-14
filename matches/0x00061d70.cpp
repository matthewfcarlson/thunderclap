// cl-flags: /O2
class C_61d70 {
  public:
    char pad[0x14];
    volatile int m;
    bool Set(int x);
};

bool C_61d70::Set(int x) {
    m = x;
    return true;
}

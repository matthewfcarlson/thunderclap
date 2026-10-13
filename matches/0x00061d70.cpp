// cl-flags: /O2
class C {
  public:
    char pad[0x14];
    volatile int m;
    bool Set(int x);
};

bool C::Set(int x) {
    m = x;
    return true;
}

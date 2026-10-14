class C_17fe80 {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};

bool C_17fe80::Set(int x) {
    m = x;
    return true;
}

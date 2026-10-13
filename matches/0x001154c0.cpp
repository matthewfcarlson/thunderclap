class X {
  public:
    char pad[0x14];
    int member;
    bool Set(int x);
};

bool X::Set(int x) {
    member = x;
    return true;
}

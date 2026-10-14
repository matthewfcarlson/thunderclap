class C {
  public:
    char pad[0x3c];
    int m3c;
    bool Set(int x);
};

bool C::Set(int x) {
    m3c = x;
    return true;
}

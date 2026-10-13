class C {
  public:
    char pad[0x28];
    int m28;
    bool Set(int x);
};

bool C::Set(int x) {
    m28 = x;
    return true;
}

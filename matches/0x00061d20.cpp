class C {
  public:
    char pad[0x44];
    int m44;
    bool Set(int v);
};

bool C::Set(int v) {
    m44 = v;
    return true;
}

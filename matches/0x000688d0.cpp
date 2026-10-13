class C {
  public:
    bool Set(int value);
    char pad[0x24];
    int m24;
};

bool C::Set(int value) {
    m24 = value;
    return true;
}

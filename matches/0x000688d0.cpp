class C_688d0 {
  public:
    bool Set(int value);
    char pad[0x24];
    int m24;
};

bool C_688d0::Set(int value) {
    m24 = value;
    return true;
}

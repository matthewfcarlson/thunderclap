class X {
  public:
    X() {}
    void Fn();
    char pad[0x224];
    char m224;
};

void X::Fn() {
    m224 = 0;
}

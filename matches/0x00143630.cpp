class X_143630 {
  public:
    char pad[0x10];
    unsigned int value;
    bool Set(unsigned int v);
};
bool X_143630::Set(unsigned int v) {
    value = v;
    return true;
}
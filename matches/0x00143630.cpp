class X {
  public:
    char pad[0x10];
    unsigned int value;
    bool Set(unsigned int v);
};
bool X::Set(unsigned int v) {
    value = v;
    return true;
}
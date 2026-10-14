class T {
  public:
    char pad[0x95];
    unsigned char value;
    bool Set(unsigned char x);
};
bool T::Set(unsigned char x) {
    value = x;
    return true;
}

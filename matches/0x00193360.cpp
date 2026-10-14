class T_193360 {
  public:
    char pad[0x95];
    unsigned char value;
    bool Set(unsigned char x);
};
bool T_193360::Set(unsigned char x) {
    value = x;
    return true;
}

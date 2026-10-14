class O_23cb70 {
  public:
    char pad[0xf];
    bool Set(char v);
};
bool O_23cb70::Set(char v) {
    ((char*)this)[0xf] = v;
    return true;
}
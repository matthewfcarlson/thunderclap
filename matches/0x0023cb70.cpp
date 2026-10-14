class O {
  public:
    char pad[0xf];
    bool Set(char v);
};
bool O::Set(char v) {
    ((char*)this)[0xf] = v;
    return true;
}
class Obj {
  public:
    char pad[0x1d];
    char value;
    bool Set(unsigned char x);
};

bool Obj::Set(unsigned char x) {
    value = x;
    return true;
}

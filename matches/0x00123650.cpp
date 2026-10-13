class Obj {
  public:
    char m[0x14];
    bool Set(unsigned char x);
};

bool Obj::Set(unsigned char x) {
    m[0x14] = x;
    return true;
}

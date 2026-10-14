class Obj {
  public:
    char pad[0x14];
    char m;
    bool Set(unsigned char x);
};

bool Obj::Set(unsigned char x) {
    m = x;
    return true;
}

class Obj {
  public:
    char pad[0x18];
    char m;
    bool Set(char c);
};

bool Obj::Set(char c) {
    m = c;
    return true;
}

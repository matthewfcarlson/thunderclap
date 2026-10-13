class Obj {
  public:
    char pad[0x20];
    char m20;
    bool Set(char v);
};

bool Obj::Set(char v) {
    m20 = v;
    return true;
}

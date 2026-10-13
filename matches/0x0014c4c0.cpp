class Obj {
  public:
    char pad[12];
    char mField;
    bool Set(unsigned char x);
};

bool Obj::Set(unsigned char x) {
    mField = x;
    return true;
}

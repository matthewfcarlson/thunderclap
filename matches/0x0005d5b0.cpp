class Obj {
  public:
    char pad[0xb8];
    int mValue;
    bool Set(int value);
};
bool Obj::Set(int value) {
    mValue = value;
    return true;
}

class Obj {
  public:
    char pad[0x13c];
    int mValue;
    bool Set(int value);
};

bool Obj::Set(int value) {
    mValue = value;
    return true;
}

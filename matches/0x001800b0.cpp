class Obj {
  public:
    char pad[0x58];
    int mValue;
    bool Set(int value);
};

bool Obj::Set(int value) {
    mValue = value;
    return true;
}

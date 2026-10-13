class Obj {
  public:
    bool Set(int value);
    char pad[0x30];
    int mValue;
};

bool Obj::Set(int value) {
    mValue = value;
    return true;
}

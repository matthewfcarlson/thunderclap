class Obj {
  public:
    bool Set(int value);
    char pad[0x34];
    int mField;
};

bool Obj::Set(int value) {
    mField = value;
    return true;
}

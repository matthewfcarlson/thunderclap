class Obj {
  public:
    char pad[12];
    int mField;
    bool Set(int value);
};

bool Obj::Set(int value) {
    mField = value;
    return true;
}
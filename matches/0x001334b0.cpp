class Obj {
  public:
    char pad[12];
    int mValue;
    bool Set(int value);
};

bool Obj::Set(int value) {
    mValue = value;
    return true;
}

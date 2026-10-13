class Obj {
  public:
    char pad[12];
    char mValue;
    bool Set(char v);
};

bool Obj::Set(char v) {
    mValue = v;
    return true;
}

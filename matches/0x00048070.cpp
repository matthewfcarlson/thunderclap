class Obj {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int arg);
};

bool Obj::Set(int arg) {
    mValue = arg;
    return true;
}

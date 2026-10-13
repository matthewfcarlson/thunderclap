class Obj {
    char pad[0x20];
    int mValue;

  public:
    bool Set(int value);
};

bool Obj::Set(int value) {
    mValue = value;
    return true;
}

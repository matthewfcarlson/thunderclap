class Obj_123630 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};

bool Obj_123630::Set(int value) {
    mValue = value;
    return true;
}

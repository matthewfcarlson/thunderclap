class Obj_17f390 {
  public:
    char pad[0x18];
    int mValue;
    bool Set(int value);
};

bool Obj_17f390::Set(int value) {
    mValue = value;
    return true;
}

class Obj_17f740 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};

bool Obj_17f740::Set(int value) {
    mValue = value;
    return true;
}

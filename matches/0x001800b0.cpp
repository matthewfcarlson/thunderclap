class Obj_1800b0 {
  public:
    char pad[0x58];
    int mValue;
    bool Set(int value);
};

bool Obj_1800b0::Set(int value) {
    mValue = value;
    return true;
}

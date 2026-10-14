class Obj_12dfe0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};

bool Obj_12dfe0::Set(int value) {
    mValue = value;
    return true;
}

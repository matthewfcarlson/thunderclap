class Obj_1aad20 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};

bool Obj_1aad20::Set(int value) {
    mValue = value;
    return true;
}

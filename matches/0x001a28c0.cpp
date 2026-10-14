class Obj_1a28c0 {
  public:
    char pad[0x104];
    int mValue;
    bool Set(int value);
};

bool Obj_1a28c0::Set(int value) {
    mValue = value;
    return true;
}

class Obj_15b180 {
  public:
    char pad[0x8c];
    int mValue;
    bool Set(int value);
};

bool Obj_15b180::Set(int value) {
    mValue = value;
    return true;
}

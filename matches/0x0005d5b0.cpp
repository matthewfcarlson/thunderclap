class Obj_5d5b0 {
  public:
    char pad[0xb8];
    int mValue;
    bool Set(int value);
};
bool Obj_5d5b0::Set(int value) {
    mValue = value;
    return true;
}

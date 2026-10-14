class Obj_192610 {
  public:
    char pad[0x24];
    int mValue;
    bool Set(int value);
};
bool Obj_192610::Set(int value) {
    mValue = value;
    return true;
}

class Obj_115120 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};
bool Obj_115120::Set(int value) {
    mValue = value;
    return true;
}
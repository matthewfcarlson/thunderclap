class Obj_14cf90 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};
bool Obj_14cf90::Set(int value) {
    mValue = value;
    return true;
}

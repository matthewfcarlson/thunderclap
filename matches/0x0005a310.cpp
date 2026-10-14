class Obj_5a310 {
  public:
    char pad[0x24];
    int m24;
    bool Set(int value);
};
bool Obj_5a310::Set(int value) {
    m24 = value;
    return true;
}

class Obj_61d10 {
  public:
    char pad[0x48];
    char flag;
    bool Set(char v);
};
bool Obj_61d10::Set(char v) {
    flag = v;
    return true;
}

class Obj_14c590 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};
bool Obj_14c590::Set(int x) {
    value = x;
    return true;
}

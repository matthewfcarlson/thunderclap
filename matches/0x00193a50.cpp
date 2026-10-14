class Obj_193a50 {
  public:
    char pad[0x70];
    int value;
    bool Set(int x);
};
bool Obj_193a50::Set(int x) {
    value = x;
    return true;
}

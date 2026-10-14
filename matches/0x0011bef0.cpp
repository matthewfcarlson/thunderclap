class Obj_11bef0 {
  public:
    char pad[0x18];
    int value;
    bool Set(int x);
};
bool Obj_11bef0::Set(int x) {
    value = x;
    return true;
}

class Obj_18ede0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};
bool Obj_18ede0::Set(int x) {
    value = x;
    return true;
}
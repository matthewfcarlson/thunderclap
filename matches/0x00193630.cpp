class Obj_193630 {
  public:
    char pad[0x110];
    int value;
    bool Set(int x);
};
bool Obj_193630::Set(int x) {
    value = x;
    return true;
}
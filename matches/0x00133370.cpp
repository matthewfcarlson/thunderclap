class Obj_133370 {
  public:
    char pad[0x18];
    int value;
    bool Set(int x);
};
bool Obj_133370::Set(int x) {
    value = x;
    return true;
}
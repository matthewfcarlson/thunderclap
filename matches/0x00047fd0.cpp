class Obj_47fd0 {
  public:
    char pad[0x50];
    int value;
    bool Set(int x);
};
bool Obj_47fd0::Set(int x) {
    value = x;
    return true;
}
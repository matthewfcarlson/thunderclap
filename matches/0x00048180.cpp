class Obj_48180 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};
bool Obj_48180::Set(int x) {
    value = x;
    return true;
}

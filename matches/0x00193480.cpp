class Obj_193480 {
  public:
    char pad[0xb0];
    int value;
    bool Set(int v);
};
bool Obj_193480::Set(int v) {
    value = v;
    return true;
}

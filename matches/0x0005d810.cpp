class Obj_5d810 {
  public:
    char pad[0x28];
    int value;
    bool Set(int v);
};
bool Obj_5d810::Set(int v) {
    value = v;
    return true;
}

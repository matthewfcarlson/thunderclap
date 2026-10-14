class Obj_115610 {
  public:
    char pad[0x24];
    int m24;
    bool Set(int v);
};
bool Obj_115610::Set(int v) {
    m24 = v;
    return true;
}

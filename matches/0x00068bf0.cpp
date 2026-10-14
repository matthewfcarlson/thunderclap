class Obj_68bf0 {
  public:
    char pad[0x18];
    int field;
    bool Set(int v);
};
bool Obj_68bf0::Set(int v) {
    field = v;
    return true;
}

class Obj_68750 {
  public:
    char pad[0x98];
    int m98;
    bool Set(int v);
};
bool Obj_68750::Set(int v) {
    m98 = v;
    return true;
}
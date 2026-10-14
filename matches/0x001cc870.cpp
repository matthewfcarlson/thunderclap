class Obj {
  public:
    char pad[0x1198];
    int m1198;
    void Set(int v);
};
void Obj::Set(int v) {
    m1198 = v;
}

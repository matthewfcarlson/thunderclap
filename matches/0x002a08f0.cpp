class Obj {
  public:
    char pad[0x50];
    int field;
    void Set(int v);
};
void Obj::Set(int v) {
    field = v;
}

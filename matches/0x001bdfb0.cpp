class Obj {
  public:
    char pad[0x20];
    int value;
    void Set(int v);
};
void Obj::Set(int v) {
    value = v;
}

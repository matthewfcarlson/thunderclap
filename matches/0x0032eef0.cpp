class Obj {
  public:
    char pad[0x8c];
    int value;
    void Set(int v);
};
void Obj::Set(int v) {
    value = v;
}

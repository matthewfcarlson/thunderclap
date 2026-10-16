class Obj {
    char pad[0x1e48];
    int value;

  public:
    void Set(int v);
};
void Obj::Set(int v) {
    value = v;
}
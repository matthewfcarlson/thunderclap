class Obj {
  public:
    char pad[0x94];
    int value;
    void Set(int x);
};
void Obj::Set(int x) {
    value = x;
}

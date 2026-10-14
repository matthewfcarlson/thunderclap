class Obj {
  public:
    char pad[0x8c];
    int value;
    void Set(int x);
};
void Obj::Set(int x) {
    value = x;
}

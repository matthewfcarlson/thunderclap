class Obj {
  public:
    char pad[0x49c];
    int value;
    void Set(int x);
};
void Obj::Set(int x) {
    value = x;
}

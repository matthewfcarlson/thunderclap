class Obj {
  public:
    char pad[0x360];
    int value;
    void Fn(int x);
};
void Obj::Fn(int x) {
    value = x;
}
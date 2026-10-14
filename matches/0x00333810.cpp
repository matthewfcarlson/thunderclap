class Obj {
  public:
    char pad[0x68];
    int m68;
    void Set(int x);
    void Other();
};
void Obj::Set(int x) {
    m68 = x;
    Other();
}

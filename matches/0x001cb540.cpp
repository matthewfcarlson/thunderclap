class Obj {
  public:
    char pad[0x3fc];
    char m3fc;
    void Set(char v);
};
void Obj::Set(char v) {
    m3fc = v;
}

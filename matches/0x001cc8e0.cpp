class Obj {
  public:
    char pad[0x11a0];
    char m;
    void Set(char v);
};

void Obj::Set(char v) {
    m = v;
}

class Obj {
  public:
    char pad[0x189];
    char m189;
    char Target(char v);
};

char Obj::Target(char v) {
    m189 = v;
    return 1;
}

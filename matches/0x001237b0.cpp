class Obj {
  public:
    char m[0x14];
    char Fn(char v);
};
char Obj::Fn(char v) {
    m[0x14] = v;
    return 1;
}

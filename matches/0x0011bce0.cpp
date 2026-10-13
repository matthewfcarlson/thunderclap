class Obj {
  public:
    char pad[0x2d];
    char m2d;
    char Set(char v);
};
char Obj::Set(char v) {
    m2d = v;
    return 1;
}
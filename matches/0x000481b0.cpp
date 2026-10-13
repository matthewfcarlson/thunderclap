class Obj {
  public:
    char pad[0x1c];
    char m;
    char Set(char v);
};
char Obj::Set(char v) {
    m = v;
    return 1;
}

class Obj {
  public:
    char m[0x0f];
    char Set(char v);
};
char Obj::Set(char v) {
    m[0x0f] = v;
    return 1;
}

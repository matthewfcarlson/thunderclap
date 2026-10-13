class Obj {
  public:
    char pad[0x28];
    char m28;
    char Set(char v);
};
char Obj::Set(char v) {
    m28 = v;
    return 1;
}

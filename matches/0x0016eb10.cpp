class Obj {
  public:
    char pad[32];
    char m20;
    char m21;
    char Set(char v);
};
char Obj::Set(char v) {
    m20 = v;
    return 1;
}
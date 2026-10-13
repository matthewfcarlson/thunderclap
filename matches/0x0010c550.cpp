class Obj {
  public:
    char pad[32];
    char m20;
    char Set(char c);
};
char Obj::Set(char c) {
    m20 = c;
    return 1;
}

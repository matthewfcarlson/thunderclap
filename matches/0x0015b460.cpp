class Obj {
  public:
    char pad[0x48];
    char f48;
    char Set(char c);
};
char Obj::Set(char c) {
    f48 = c;
    return 1;
}

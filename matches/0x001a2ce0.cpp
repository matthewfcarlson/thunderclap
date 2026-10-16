class Obj {
  public:
    char pad[0x188];
    char value;
    char Set(char x);
};
char Obj::Set(char x) {
    value = x;
    return 1;
}
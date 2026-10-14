class Obj {
  public:
    char pad[0x75];
    char m;
    char Set(char x);
};

char Obj::Set(char x) {
    m = x;
    return 1;
}

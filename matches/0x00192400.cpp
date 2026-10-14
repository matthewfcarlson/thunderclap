class Obj_192400 {
  public:
    char pad[0x75];
    char m;
    char Set(char x);
};

char Obj_192400::Set(char x) {
    m = x;
    return 1;
}

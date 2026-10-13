class Obj {
  public:
    char m[0x28];
    char Set(char a);
};

char Obj::Set(char a) {
    m[0x28] = a;
    return 1;
}

class Obj {
  public:
    char m[0x10];
    char Set(int x);
};
char Obj::Set(int x) {
    *(int*)(m + 0x10) = x;
    return 1;
}

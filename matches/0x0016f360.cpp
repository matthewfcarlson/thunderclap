class Obj {
  public:
    char m[0xc];
    char Set(int x);
};

char Obj::Set(int x) {
    *(int*)(m + 0xc) = x;
    return 1;
}

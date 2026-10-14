class Obj {
  public:
    char m[0x10];
    char Set(int v);
};

char Obj::Set(int v) {
    *(int*)(m + 0x10) = v;
    return 1;
}

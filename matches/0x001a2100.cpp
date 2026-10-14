class Obj {
  public:
    char m[0x10];
    char Fn(int);
};

char Obj::Fn(int v) {
    *(int*)(m + 0x10) = v;
    return 1;
}

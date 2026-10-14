class Obj {
  public:
    char m[0xd8];
    char Fn(int x);
};
char Obj::Fn(int x) {
    *(int*)(m + 0xd8) = x;
    return 1;
}
class Obj {
  public:
    char m[0x18];
    char Fn(int x);
};
char Obj::Fn(int x) {
    *(int*)((char*)m + 0x18) = x;
    return 1;
}

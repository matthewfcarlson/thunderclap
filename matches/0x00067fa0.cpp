class Obj {
  public:
    char m[0x44];
    char Fn(int a);
};
char Obj::Fn(int a) {
    *(int*)(m + 0x44) = a;
    return 1;
}

class Obj {
  public:
    char pad[0x134];
    int m134;
    char FUN_001a2a40(int);
};
char Obj::FUN_001a2a40(int x) {
    m134 = x;
    return 1;
}
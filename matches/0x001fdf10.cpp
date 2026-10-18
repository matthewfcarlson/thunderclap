class Obj {
  public:
    char pad[0x234];
    char* data;
    char check(int x);
};
struct This_FUN_001fcff0 {
    int FUN_001fcff0(int);
};
char Obj::check(int x) {
    int i = ((This_FUN_001fcff0*)this)->FUN_001fcff0(x);
    if (i == -1)
        return 0;
    return *(int*)(data + i * 0xc70 + 0x458) == 2;
}
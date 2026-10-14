class Obj {
  public:
    char pad[0x40];
    char Fn(int x);
};
char Obj::Fn(int x) {
    *(int*)((char*)this + 0x40) = x;
    return 1;
}

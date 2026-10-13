class Obj {
  public:
    char Fn(int x);
    char pad[0xc];
};
char Obj::Fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
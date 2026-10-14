class Obj {
  public:
    char f(int x);
};
char Obj::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}

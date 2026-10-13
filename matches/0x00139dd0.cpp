class Obj {
  public:
    char f(int v);
};

char Obj::f(int v) {
    *(int*)((char*)this + 0x24) = v;
    return 1;
}

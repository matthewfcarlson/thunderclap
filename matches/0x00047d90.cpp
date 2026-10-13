class Obj {
  public:
    char fn(int x);
    char pad[12];
};

char Obj::fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}

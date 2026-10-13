class Obj {
  public:
    char Set(int x);
};
char Obj::Set(int x) {
    *(int*)((char*)this + 0x10) = x;
    return 1;
}

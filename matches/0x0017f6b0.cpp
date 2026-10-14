class Obj {
  public:
    char Set(int x);
    char m[0xc];
};
char Obj::Set(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
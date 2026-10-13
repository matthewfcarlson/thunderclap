class Obj {
  public:
    char m[12];
    char Set(int x);
};
char Obj::Set(int x) {
    *(int*)((char*)this + 12) = x;
    return 1;
}

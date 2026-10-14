class Obj {
  public:
    char m[0x98];
    char Set(int x);
};
char Obj::Set(int x) {
    *(int*)((char*)this + 0x98) = x;
    return 1;
}
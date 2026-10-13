class Obj {
  public:
    char pad[0x20];
    char Set(int x);
};
char Obj::Set(int x) {
    *(int*)((char*)this + 0x20) = x;
    return 1;
}

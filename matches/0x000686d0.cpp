class Obj {
  public:
    char Set(int x);
    char pad[0x78];
};
char Obj::Set(int x) {
    *(int*)((char*)this + 0x78) = x;
    return 1;
}

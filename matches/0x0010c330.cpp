class Obj {
  public:
    char Set(int x);
    char pad[12];
};
char Obj::Set(int x) {
    *(int*)((char*)this + 12) = x;
    return 1;
}

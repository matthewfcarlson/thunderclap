class Obj {
  public:
    char Set(int v);
    char pad[0x10];
};
char Obj::Set(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}

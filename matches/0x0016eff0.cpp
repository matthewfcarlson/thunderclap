class Obj {
  public:
    char m[0x48];
    char Set(int v);
};
char Obj::Set(int v) {
    *(int*)((char*)this + 0x48) = v;
    return 1;
}
class Obj {
  public:
    char Set(int v);
    char m[0x20];
};
char Obj::Set(int v) {
    *((int*)((char*)this + 0x20)) = v;
    return 1;
}
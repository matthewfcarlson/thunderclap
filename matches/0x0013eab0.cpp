class Obj {
  public:
    char Pad[0x20];
    char Set(int v);
};
char Obj::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}

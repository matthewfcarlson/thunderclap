class Obj {
  public:
    char m[0xc];
    char Set(int v);
};
char Obj::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}

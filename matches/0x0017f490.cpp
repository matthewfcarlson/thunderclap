class Obj {
  public:
    char Set(int v);
    char pad[12];
};

char Obj::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}

class Obj {
  public:
    char pad[0x28];
    char Set(int v);
};

char Obj::Set(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}

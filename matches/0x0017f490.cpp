class Obj_17f490 {
  public:
    char Set(int v);
    char pad[12];
};

char Obj_17f490::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}

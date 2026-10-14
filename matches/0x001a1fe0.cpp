class Obj_1a1fe0 {
  public:
    char pad[0x28];
    char Set(int v);
};

char Obj_1a1fe0::Set(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}

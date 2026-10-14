class Obj_14cc20 {
  public:
    char pad[0x34];
    void* m;
    char Set(void* v);
};

char Obj_14cc20::Set(void* v) {
    m = v;
    return 1;
}

class Obj {
  public:
    char pad[0x34];
    void* m;
    char Set(void* v);
};

char Obj::Set(void* v) {
    m = v;
    return 1;
}

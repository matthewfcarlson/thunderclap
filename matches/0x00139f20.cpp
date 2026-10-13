class Obj {
  public:
    char pad[0x30];
    void* m30;
    char Set(void* v);
};
char Obj::Set(void* v) {
    m30 = v;
    return 1;
}

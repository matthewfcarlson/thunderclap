class Obj_139f20 {
  public:
    char pad[0x30];
    void* m30;
    char Set(void* v);
};
char Obj_139f20::Set(void* v) {
    m30 = v;
    return 1;
}

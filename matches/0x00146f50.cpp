class Obj {
  public:
    char pad[0x38];
    void* m38;
    unsigned char Set(void* v);
};
unsigned char Obj::Set(void* v) {
    m38 = v;
    return 1;
}

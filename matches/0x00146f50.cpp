class Obj_146f50 {
  public:
    char pad[0x38];
    void* m38;
    unsigned char Set(void* v);
};
unsigned char Obj_146f50::Set(void* v) {
    m38 = v;
    return 1;
}

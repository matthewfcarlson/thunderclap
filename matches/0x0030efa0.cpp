class C_30efa0 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void second(int);
    void third();
    void target(int);
};
void C_30efa0::target(int arg) {
    first();
    ((C_30efa0*)((char*)this + 0x14))->second(arg);
    value = 2;
    third();
}
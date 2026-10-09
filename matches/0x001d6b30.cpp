class Thing {
  public:
    char pad[0x17c];
    int* FUN_001d6b30();
};
int* Thing::FUN_001d6b30() {
    return (int*)((char*)this + 0x17c);
}
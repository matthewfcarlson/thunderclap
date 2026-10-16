class Thing {
  public:
    Thing(int) throw();
    char pad[0x8c];
};
void* operator new(unsigned int) throw();
Thing* __cdecl FUN_00327ef0(int x) {
    return new Thing(x);
}
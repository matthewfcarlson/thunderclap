typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Thing {
  public:
    Thing(int) throw();
    char pad[0x80];
};
Thing* __cdecl FUN_00327e60(int x) {
    return new Thing(x);
}
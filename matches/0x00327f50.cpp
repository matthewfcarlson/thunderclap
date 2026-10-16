typedef unsigned int size_t;
void* __cdecl operator new(size_t);
class Thing {
  public:
    Thing(int) throw();
    char pad[0xa4];
};
Thing* __cdecl FUN_00327f50(int n) {
    return new Thing(n);
}

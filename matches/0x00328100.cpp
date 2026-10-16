class Obj {
    char pad[0x98];

  public:
    Obj(int) throw();
};
void* __cdecl operator new(unsigned int) throw();
Obj* __cdecl FUN_00328100(int n) {
    return new Obj(n);
}
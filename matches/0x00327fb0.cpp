typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Obj {
    char pad[0xa0];

  public:
    Obj(int) throw();
};
Obj* __cdecl Make(int x) {
    return new Obj(x);
}

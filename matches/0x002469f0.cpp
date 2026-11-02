class Callee {
  public:
    void Fn(void*, void*, int, void*);
};
class Obj {
  public:
    char pad[0x1c];
    Callee* ptr;
};
extern "C" void FUN_002469f0(Obj* o, void* a, void* b, void* c) {
    o->ptr->Fn(a, b, 1, c);
}
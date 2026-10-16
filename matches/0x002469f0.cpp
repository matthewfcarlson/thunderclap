class Callee {
  public:
    void Fn(void*, void*, int, void*);
};
class Obj {
  public:
    char pad[0x1c];
    Callee* ptr;
};
void fn(Obj* o, void* a, void* b, void* c) {
    o->ptr->Fn(a, b, 1, c);
}
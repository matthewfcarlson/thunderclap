extern int vt;
void __cdecl thunk_FUN_00267090(void*);
class Obj {
  public:
    int* vptr;
    char pad[0x10];
    void* m;
    void Fn();
};
void Obj::Fn() {
    vptr = &vt;
    thunk_FUN_00267090(m);
}

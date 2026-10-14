extern int vt_338520;
void __cdecl thunk_FUN_00267090(void*);
class Obj_338520 {
  public:
    int* vptr;
    char pad[0x10];
    void* m;
    void Fn();
};
void Obj_338520::Fn() {
    vptr = &vt_338520;
    thunk_FUN_00267090(m);
}

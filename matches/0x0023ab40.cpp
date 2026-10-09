struct Obj {
    char pad[0x100];
    Obj* next;
};
extern void __cdecl thunk_FUN_00267090(Obj*);
class C {
  public:
    char pad[0x12c];
    int count;
    char pad1[0x0c];
    void f();
};
void C::f() {
    int n = count;
    if (--n >= 0) {
        char* p = (char*)this + 0x13c + n * 0x18;
        int left = n + 1;
        do {
            if (*((int*)p - 1) == 4) {
                Obj* x = *(Obj**)p;
                while (x) {
                    Obj* cur = x;
                    x = x->next;
                    thunk_FUN_00267090(cur);
                }
            }
            p -= 0x18;
            --left;
        } while (left);
    }
    count = 0;
}
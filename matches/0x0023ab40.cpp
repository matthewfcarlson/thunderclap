struct Obj_23ab40 {
    char pad[0x100];
    Obj_23ab40* next;
};
extern void __cdecl thunk_FUN_00267090(Obj_23ab40*);
class C_23ab40 {
  public:
    char pad[0x12c];
    int count;
    char pad1[0x0c];
    void f();
};
void C_23ab40::f() {
    int n = count;
    if (--n >= 0) {
        char* p = (char*)this + 0x13c + n * 0x18;
        int left = n + 1;
        do {
            if (*((int*)p - 1) == 4) {
                Obj_23ab40* x = *(Obj_23ab40**)p;
                while (x) {
                    Obj_23ab40* cur = x;
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
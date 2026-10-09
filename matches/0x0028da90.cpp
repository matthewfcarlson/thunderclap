// Same code shape as 0x0028b4d0 (propagated; names are from that function)
struct Obj { virtual void f0(); virtual void f1(); };
void thunk(int*);
class IntChannel { public: char pad0[12]; Obj* volatile mObj; char pad10[4]; int* m14; int* m18; void vfunc_1(); };
void IntChannel::vfunc_1() {
    if (mObj == 0) thunk(m18);
    m18 = 0;
    if (mObj == 0) {
        thunk(m14);
        m14 = 0;
        return;
    }
    Obj* p = mObj;
    if (p) { p->f1(); mObj = 0; }
    m14 = 0;
}
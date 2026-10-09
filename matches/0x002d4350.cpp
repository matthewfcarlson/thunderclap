typedef unsigned int U;
extern U vt1;
extern U vt2;
void drop(U);
class Obj { public: U vptr; U x[3]; U a[8]; void f(); };
void Obj::f() {
    vptr = (U)&vt1;
    drop(a[0]); drop(a[1]); drop(a[2]); drop(a[3]);
    drop(a[4]); drop(a[5]); drop(a[6]); drop(a[7]);
    vptr = (U)&vt2;
}

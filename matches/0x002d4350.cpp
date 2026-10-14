typedef unsigned int U_2d4350;
extern U_2d4350 vt1_2d4350;
extern U_2d4350 vt2_2d4350;
void drop(U_2d4350);
class Obj_2d4350 {
  public:
    U_2d4350 vptr;
    U_2d4350 x[3];
    U_2d4350 a[8];
    void f();
};
void Obj_2d4350::f() {
    vptr = (U_2d4350)&vt1_2d4350;
    drop(a[0]);
    drop(a[1]);
    drop(a[2]);
    drop(a[3]);
    drop(a[4]);
    drop(a[5]);
    drop(a[6]);
    drop(a[7]);
    vptr = (U_2d4350)&vt2_2d4350;
}

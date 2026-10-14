// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022c1b0 @ 0x0022c1b0
struct Vec_22c1b0 { float x,y,z; void FUN_0022d180(); };
struct Matrix { Vec_22c1b0 a; float pad0; Vec_22c1b0 b; float pad1; Vec_22c1b0 c; void target(); };
void Matrix::target() {
 Vec_22c1b0 first = a;
 Vec_22c1b0 second = b;
 first.FUN_0022d180();
 Vec_22c1b0 third;
 third.x = second.z * first.y - second.y * first.z;
 third.y = first.z * second.x - second.z * first.x;
 third.z = second.y * first.x - first.y * second.x;
 third.FUN_0022d180();
 a = first;
 b.x = third.y * first.z - third.z * first.y;
 b.y = third.z * first.x - first.z * third.x;
 b.z = first.y * third.x - third.y * first.x;
 c = third;
}

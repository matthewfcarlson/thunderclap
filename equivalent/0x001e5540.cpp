// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001e5540 @ 0x001e5540
struct Vector { float x,y,z; };
struct Matrix {
 float data[16];
 void FUN_0022b980();
 void FUN_0022be40(const Vector*);
 void FUN_0022bc20(float,float,float);
};
struct Handle {
 char data[8];
 Handle* FUN_0027b0e0(void*);
 void FUN_0027af50();
};
struct Object {
 void FUN_001e43b0(Handle*,Handle*,Matrix*,int);
 void target(void* a,void* b,Vector position,float x,float y,float z);
};
void Object::target(void* a,void* b,Vector position,float x,float y,float z) {
 if(a && b) {
 Matrix matrix;
 matrix.FUN_0022b980();
 matrix.FUN_0022be40(&position);
 matrix.FUN_0022bc20(x*0.0174533f,y*0.0174533f,z*0.0174533f);
 Handle first,second;
 Handle* pb=first.FUN_0027b0e0(b);
 Handle* pa=second.FUN_0027b0e0(a);
 FUN_001e43b0(pa,pb,&matrix,1);
 second.FUN_0027af50();
 first.FUN_0027af50();
 }
}
// STATUS: equivalent (tools/equiv.py level 3: 19466 inputs, branch coverage 4/4)
// FUN_001e5540 @ 0x001e5540
struct Vector { float x,y,z; };
struct Matrix {
 float data[16];
 void FUN_0022b980();
 void FUN_0022be40(const Vector*);
 void FUN_0022bc20(float,float,float);
};
struct Handle_1e5540 {
 char data[8];
 Handle_1e5540* FUN_0027b0e0(void*);
 void FUN_0027af50();
};
struct Object {
 void FUN_001e43b0(Handle_1e5540*,Handle_1e5540*,Matrix*,int);
 void target(void* a,void* b,Vector position,float x,float y,float z);
};
void Object::target(void* a,void* b,Vector position,float x,float y,float z) {
 if(a && b) {
 Matrix matrix;
 matrix.FUN_0022b980();
 matrix.FUN_0022be40(&position);
 matrix.FUN_0022bc20(x*0.0174532924f,y*0.0174532924f,z*0.0174532924f);
 Handle_1e5540 first,second;
 Handle_1e5540* pb=first.FUN_0027b0e0(b);
 Handle_1e5540* pa=second.FUN_0027b0e0(a);
 FUN_001e43b0(pa,pb,&matrix,1);
 second.FUN_0027af50();
 first.FUN_0027af50();
 }
}
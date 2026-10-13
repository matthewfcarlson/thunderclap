// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00080f60 @ 0x00080f60
struct Vec { float x,y,z; };
struct Matrix;
struct Rotation { float x,y,z,w; void FUN_0022b370(const Matrix*); void FUN_0022b650(Matrix*); };
struct Matrix { float m[16]; void FUN_0022c3b0(const Vec*, Vec*); };
void __cdecl FUN_0022b080(Rotation*, const Rotation*, const Vec*);
struct First { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void query(int,int,Vec*); };
struct Second { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void query(int,Vec*); };
void __cdecl FUN_00080f60(First* first, Second* second, const Matrix* input, int value, int extra, Vec* result) {
 struct Locals { Vec a; Vec b; float padding; Rotation rotation; Matrix matrix; } local;
 result->z=0.0f; result->y=0.0f; result->x=0.0f;
 if(first) first->query(value,extra,&local.a); else { local.a.z=0.0f;local.a.y=0.0f;local.a.x=0.0f; }
 if(second) {
 local.rotation.FUN_0022b370(input);
 second->query(value,&local.b);
 local.b.x=-local.b.x; local.b.y=-local.b.y; local.b.z=-local.b.z;
 FUN_0022b080(&local.rotation,&local.rotation,&local.b);
 local.rotation.FUN_0022b650(&local.matrix);
 } else { local.matrix=*input; }
 local.matrix.FUN_0022c3b0(&local.a,result);
}
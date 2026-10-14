// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b9230 @ 0x002b9230
struct Vec3 { float x,y,z; };
struct Object { char pad[0x30]; Vec3 position; };
struct Matrix { float values[16]; void FUN_0022b980(); void FUN_0022ccf0(Vec3*); void FUN_0022ca90(Matrix*, Matrix*); void FUN_0022be40(Vec3*); };
struct Owner { char pad[0x40]; Matrix matrix; int FUN_002b8f60(void*, Matrix*, void*, Object*, void*); int target(void*, Object*, void*, Object*, void*); };
int Owner::target(void* a, Object* b, void* c, Object* d, void* e) {
 Vec3 first=b->position;
 Vec3 second=d->position;
 Vec3 delta; delta.x=first.x-second.x; delta.y=first.y-second.y; delta.z=first.z-second.z;
 Matrix translation; translation.FUN_0022b980(); translation.FUN_0022ccf0(&delta);
 Matrix result; result.FUN_0022ca90(&matrix,&translation); result.FUN_0022be40(&first);
 return FUN_002b8f60(a,&result,c,d,e);
}
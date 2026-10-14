// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0003a440 @ 0x0003a440
extern "C" double __cdecl cos(double);
struct Vec_3a440 { float x,y,z; float FUN_0022d110(); };
struct Object;
struct Query_3a440 {
 bool FUN_00039440(Object*,Vec_3a440*,Object**,int);
 bool test(Vec_3a440* origin,Vec_3a440* direction,float angle,float distance,Object* object);
};
bool Query_3a440::test(Vec_3a440* origin,Vec_3a440* direction,float angle,float distance,Object* object) {
 if (!object) return false;
 Vec_3a440 hit; hit.x=0; hit.y=0; hit.z=0;
 Object* input=object;
 object=0;
 if (!FUN_00039440(input,&hit,&object,0)) return false;
 Vec_3a440 delta;
 delta.x=hit.x-origin->x;
 delta.y=hit.y-origin->y;
 delta.z=hit.z-origin->z;
 float length=delta.FUN_0022d110();
 if (length>distance) return false;
 double dot=(double)delta.z*direction->z+(double)delta.y*direction->y+(double)delta.x*direction->x;
 return !(cos((double)angle*0.5f)>dot);
}
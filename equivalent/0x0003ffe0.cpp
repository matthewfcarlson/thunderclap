// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_0003ffe0 @ 0x0003ffe0
struct Vector { float x,y,z; };
struct Parent_3ffe0 { char pad[0x12c]; int value; };
struct Object {
 char pad[0x328]; int current; unsigned char disabled; char pad2[7]; Parent_3ffe0* parent;
 void FUN_000350c0(Vector*);
 void FUN_00035dc0(int);
 bool FUN_0003a440(Vector*,int,int,int,int);
 int FUN_00039c60(Vector*,int,int,int,int,int,int);
 int target(int a,int b,unsigned char allow,int fallback,int mode);
};
int Object::target(int a,int b,unsigned char allow,int fallback,int mode) {
 Vector v; v.x=0; v.y=0; v.z=0;
 FUN_000350c0(&v);
 FUN_00035dc0(mode);
 int result=current;
 if (!disabled) {
  if (!FUN_0003a440(&v,mode,a,b,result)) result=0;
 }
 if(result) return result;
 if(!allow) return result;
 if(FUN_0003a440(&v,mode,a,b,fallback) && fallback) return fallback;
 result=FUN_00039c60(&v,mode,a,b,0,0,0);
 if(result) return result;
 if(!parent) return result;
 result=parent->value;
 if(!FUN_0003a440(&v,mode,a,b,result)) return 0;
 return result;
}

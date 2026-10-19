// STATUS: equivalent (tools/equiv.py level 3: 17813 inputs, branch coverage 10/10)
// FUN_001f64c0 @ 0x001f64c0
// cl-flags: /GS
struct Vec_1f64c0 { float x,y,z; };
struct Transform_1f64c0 { char pad[0x30]; Vec_1f64c0 a,b,c; };
void __cdecl FUN_0024ca70(Vec_1f64c0*);
void __cdecl FUN_0024cab0(Vec_1f64c0*,Vec_1f64c0*);
struct Child_1f64c0 { void FUN_001f5860(unsigned); };
struct Object {
 char pad0[8]; Child_1f64c0* children[32]; int count;
 char pad1[0x328-0x8c]; Transform_1f64c0* transform;
 int pad2; int state;
 void FUN_001f4140(int);
 void FUN_001f5c20(unsigned);
 void FUN_001f63a0();
 void FUN_001f64c0(unsigned arg, char enabled);
};
void Object::FUN_001f64c0(unsigned arg, char enabled) {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 if (enabled && state == 0) {
  if (transform) {
   FUN_0024ca70(&transform->a);
   FUN_0024cab0(&transform->b, &transform->c);
  }
  FUN_001f4140(1);
  FUN_001f5c20(arg);
  FUN_001f63a0();
 } else {
  FUN_001f4140(0);
  for (int i=0; i<count; ++i) children[i]->FUN_001f5860(arg);
 }
}

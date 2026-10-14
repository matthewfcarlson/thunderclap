// STATUS: equivalent (tools/equiv.py level 3: 583 inputs, branch coverage 10/10)
// FUN_001f64c0 @ 0x001f64c0
extern unsigned DAT_004d9968;
void __fastcall __security_check_cookie(unsigned);
struct Vec { float x,y,z; };
struct Transform { char pad[0x30]; Vec a,b,c; };
void __cdecl FUN_0024ca70(Vec*);
void __cdecl FUN_0024cab0(Vec*,Vec*);
struct Child { void FUN_001f5860(unsigned); };
struct Object {
 char pad0[8]; Child* children[32]; int count;
 char pad1[0x328-0x8c]; Transform* transform;
 int pad2; int state;
 void FUN_001f4140(int);
 void FUN_001f5c20(unsigned);
 void FUN_001f63a0();
 void FUN_001f64c0(unsigned arg, char enabled);
};
void Object::FUN_001f64c0(unsigned arg, char enabled) {
 unsigned cookie = DAT_004d9968;
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
 __security_check_cookie(cookie);
}

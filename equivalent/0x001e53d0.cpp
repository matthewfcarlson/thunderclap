// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e53d0 @ 0x001e53d0
struct Vec_1e53d0 { float x,y,z; };
struct PositionSource_1e53d0 { void FUN_00059a50(Vec_1e53d0*); };
struct Actor_1e53d0 { char pad0[0x10]; PositionSource_1e53d0* source; char pad1[0x2144-0x14]; int handle; void FUN_00036d40(int); };
extern bool __cdecl FUN_00202560(Vec_1e53d0*,float,int,Vec_1e53d0*,Vec_1e53d0*,int,int,int);
extern int __cdecl FUN_001d68e0(int);
struct Target_1e53d0 { Vec_1e53d0* FUN_001dcb00(Vec_1e53d0*,Vec_1e53d0*); void FUN_001e4c40(int,Vec_1e53d0*,int,int,int,int); void FUN_001e53d0(Actor_1e53d0*); };
void Target_1e53d0::FUN_001e53d0(Actor_1e53d0* actor) {
 Vec_1e53d0 position, hit, extra, transformed;
 actor->source->FUN_00059a50(&position);
 position.y += 0.5f;
 if (!FUN_00202560(&position,20.0f,0,&hit,&extra,0,0,0)) {
   hit = position;
   position.y += 0.5f;
 }
 position = *FUN_001dcb00(&transformed,&hit);
 int result = FUN_001d68e0(actor->handle);
 FUN_001e4c40(result,&position,actor->handle,0,0,1);
 actor->FUN_00036d40(0);
}

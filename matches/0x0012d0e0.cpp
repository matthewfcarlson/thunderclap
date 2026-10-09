typedef unsigned int u32;
extern u32 __cdecl FUN_002343e0(u32, void*);
struct Obj { void Fn(u32); };
struct Factory { u32 vft; };
void __cdecl target(Obj* a, u32 b) {
  Factory local;
  local.vft = 0x410ec0;
  u32 x = FUN_002343e0(b, &local);
  a->Fn(x);
}

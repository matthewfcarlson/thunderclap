// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00328130 @ 0x00328130
typedef void (__cdecl *Callback)();
void __cdecl FUN_00327e60();
void __cdecl FUN_00327e90();
void __cdecl FUN_00327ec0();
void __cdecl FUN_00327ef0();
void __cdecl FUN_00327f20();
void __cdecl FUN_00327f50();
void __cdecl FUN_00327f80();
void __cdecl FUN_00327fb0();
void __cdecl FUN_00327fe0();
void __cdecl FUN_00328010();
void __cdecl FUN_00328040();
void __cdecl FUN_00328070();
void __cdecl FUN_003280a0();
void __cdecl FUN_003280d0();
void __cdecl FUN_00328100();
void __cdecl FUN_00327c20(const char*, Callback, int);
void __cdecl FUN_00328130() {
 FUN_00327c20("error", FUN_00327e60, 0);
 FUN_00327c20("simple", FUN_00327e90, 0);
 FUN_00327c20("lightweight", FUN_00327e90, 0);
 FUN_00327c20("lightmap", FUN_00327ec0, 0);
 FUN_00327c20("environment", FUN_00327ef0, 0);
 FUN_00327c20("projtex", FUN_00327f20, 0);
 FUN_00327c20("pointsprite", FUN_00327f50, 0);
 FUN_00327c20("layered", FUN_00327f80, 0);
 FUN_00327c20("layeredlmap", FUN_00327fb0, 0);
 FUN_00327c20("toon2", FUN_00328010, 0);
 FUN_00327c20("toon", FUN_00328040, 0);
 FUN_00327c20("refract", FUN_00327fe0, 0);
 FUN_00327c20("spheremap", FUN_00328070, 0);
 FUN_00327c20("bumpmap", FUN_003280d0, 0);
 FUN_00327c20("layeredReflect", FUN_003280a0, 0);
 FUN_00327c20("fbeffectsshader", FUN_00328100, 0);
}

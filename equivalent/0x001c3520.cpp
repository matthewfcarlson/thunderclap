// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 6/6)
// FUN_001c3520 @ 0x001c3520
#include "compat/ptr.h"
#include "gen/pure3d.h"
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern void* __cdecl FUN_00263ea0(unsigned);
struct MainObject { MainObject* FUN_001c1a40(); };
struct Vec_1c3520 { void FUN_0022b980(); char data[80]; };
struct DirectionalLight_nv_1c3520 {
    pure3d::DirectionalLight* FUN_002a2e70();
    void FUN_002a2ef0(float,float,float);
    void FUN_002a07a0(int);
};
struct LightGroup_nv_1c3520 {
    pure3d::LightGroup* FUN_002a1140(int);
};
struct Target_1c3520 { MainObject* object; char pad[24]; Vec_1c3520 vec; unsigned char flag; char pad2[3]; pure3d::DirectionalLight* effect; pure3d::LightGroup* other; void Run(); };
void Target_1c3520::Run() {
 int old = FUN_00266da0(15);
 MainObject* p = (MainObject*)FUN_0008d690(0x10c);
 object = p ? p->FUN_001c1a40() : 0;
 vec.FUN_0022b980();
 flag = 0;
 pure3d::DirectionalLight* e = (pure3d::DirectionalLight*)FUN_00263ea0(0x68);
 effect = e ? ((DirectionalLight_nv_1c3520*)(e))->FUN_002a2e70() : 0;
 effect->vfunc_0();
 ((DirectionalLight_nv_1c3520*)(effect))->FUN_002a2ef0(1.0f,-1.0f,1.0f);
 ((DirectionalLight_nv_1c3520*)(effect))->FUN_002a07a0(-1);
 pure3d::LightGroup* o = (pure3d::LightGroup*)FUN_00263ea0(0x28);
 other = o ? ((LightGroup_nv_1c3520*)(o))->FUN_002a1140(0) : 0;
 other->vfunc_0();
 FUN_00266da0(old);
}
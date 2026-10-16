// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000d6a20 @ 0x000d6a20
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

struct Data_d6a20 { float x,y,z; };   
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(float,float); virtual void v6(); virtual void v7(float); virtual void v8(); virtual void v9(float);
 char pad[28]; int field20; char pad24[8]; int field2c;
 Node* FUN_00294880(); Node* FUN_002939a0(); void FUN_00293e90(unsigned); void FUN_00293af0(Data_d6a20*); void FUN_00293a90(Data_d6a20*); void FUN_00294980(Node*);
};
struct Manager_d6a20 {virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual float v16();}; 
extern void* __cdecl FUN_0008d690(unsigned); extern void* __cdecl FUN_00263ea0(unsigned); extern void __cdecl FUN_0009f790(float,float,float*,float*);
struct Target_d6a20 {char pad0[4]; Node* first; char pad8[36]; Node* second; void FUN_000d6a20();};
void Target_d6a20::FUN_000d6a20(){
 Node* p=(Node*)FUN_0008d690(0x140); first=p?p->FUN_00294880():0; first->v0(); first->field20=0; first->FUN_00293e90(0xff282828); first->field2c=2;
 p=(Node*)FUN_00263ea0(0xf8); second=p?p->FUN_002939a0():0; second->v0(); second->v7(0.1f); second->v9(100.0f); second->FUN_00293af0(((Data_d6a20*)&DAT_004a0a74)); second->FUN_00293a90(((Data_d6a20*)&DAT_004a0a80));
 float aspect=(*(Manager_d6a20**)&DAT_0052c2a4)->v16(); float a,b; FUN_0009f790(90.0f,aspect,&a,&b); second->v5(a*(*(float*)&DAT_003f32b8),1.0f); first->FUN_00294980(second);
}
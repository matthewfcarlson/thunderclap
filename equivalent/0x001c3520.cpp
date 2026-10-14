// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c3520 @ 0x001c3520
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_0008d690(unsigned);
extern void* __cdecl FUN_00263ea0(unsigned);
struct MainObject { MainObject* FUN_001c1a40(); };
struct Vec { void FUN_0022b980(); char data[80]; };
struct Effect { virtual void Init(); Effect* FUN_002a2e70(); void FUN_002a2ef0(float,float,float); void FUN_002a07a0(int); };
struct Other { virtual void Init(); Other* FUN_002a1140(int); };
struct Target { MainObject* object; char pad[24]; Vec vec; unsigned char flag; char pad2[3]; Effect* effect; Other* other; void Run(); };
void Target::Run() {
 int old = FUN_00266da0(15);
 MainObject* p = (MainObject*)FUN_0008d690(0x10c);
 object = p ? p->FUN_001c1a40() : 0;
 vec.FUN_0022b980();
 flag = 0;
 Effect* e = (Effect*)FUN_00263ea0(0x68);
 effect = e ? e->FUN_002a2e70() : 0;
 effect->Init();
 effect->FUN_002a2ef0(1.0f,-1.0f,1.0f);
 effect->FUN_002a07a0(-1);
 Other* o = (Other*)FUN_00263ea0(0x28);
 other = o ? o->FUN_002a1140(0) : 0;
 other->Init();
 FUN_00266da0(old);
}
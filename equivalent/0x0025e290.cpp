// STATUS: equivalent (tools/equiv.py level 3: 19056 inputs, branch coverage 0/0)
// FUN_0025e290 @ 0x0025e290
// FUN_0025e290 @ 0x0025e290
struct Object { char pad[0x10]; unsigned char flag; char pad2[3]; int a,b,c,d,e; };
// equiv-conv: FUN_0025e230 edi
void __cdecl FUN_0025e230(Object*); void __cdecl FUN_0025e290(Object* obj) { obj->a=0; obj->b=0; obj->flag=0; obj->c=0; obj->d=0; obj->e=0; FUN_0025e230(obj); volatile int hold = 0; (void)hold; }

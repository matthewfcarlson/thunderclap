// STATUS: equivalent (tools/equiv.py level 3: 16562 inputs, branch coverage 0/0)
// FUN_0025e550 @ 0x0025e550
// FUN_0025e550 @ 0x0025e550
struct Object { int first; int fourth; int third; float half; unsigned char flag; char pad[3]; int a,b,c,d,e; };
// equiv-conv: FUN_0025e230 edi
void __cdecl FUN_0025e230(Object*); void __cdecl FUN_0025e550(Object* obj, int first, int third, int fourth) { obj->first=first; obj->third=third; obj->fourth=fourth; obj->half=0.5f; obj->a=0; obj->b=0; obj->flag=0; obj->c=0; obj->d=0; obj->e=0; FUN_0025e230(obj); (void)*(volatile unsigned char*)&obj->flag; }

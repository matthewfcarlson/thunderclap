typedef unsigned int u32;
struct Obj { char pad[0x24]; void (__cdecl *fn)(u32,u32); u32 value; };
void __cdecl FUN_002ea2a0(Obj*,Obj*,int);
int __cdecl FUN_002eaf30(Obj* a, Obj* b) {
    FUN_002ea2a0(a,b,0);
    b->fn(b->value,a->value);
    b->fn(b->value,*((u32*)((char*)a+0x24)));
    b->fn(b->value,(u32)a);
    return 0;
}
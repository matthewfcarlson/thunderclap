// STATUS: equivalent (tools/equiv.py level 3: 284 inputs, branch coverage 11/11)
// FUN_0024a3c0 @ 0x0024a3c0
struct Link {
    void FUN_0025dd00(int a);
};
struct Obj {
    char pad0[8];
    Link *link;
    int state;
};
void __cdecl FUN_00249810(int x);
// equiv-conv: FUN_002498d0 ebx
void FUN_002498d0(Obj *o);
void __cdecl FUN_00248670(int a);
void __cdecl FUN_00248780(int a);

// equiv-conv: FUN_0024a3c0 eax ecx stack stack
bool FUN_0024a3c0(Obj *o, int x, int unused, int a)
{
    int s;
    do {
        s = o->state;
        switch (s) {
        case 1:
            FUN_00249810(x);
            break;
        case 3:
            FUN_002498d0(o);
            break;
        case 4:
            FUN_00248670(a);
            break;
        case 5:
            FUN_00248780(a);
            break;
        }
        o->link->FUN_0025dd00(a);
    } while (s != o->state);
    return o->state == 0;
}

typedef unsigned int uint;
extern int __cdecl MakeThing(void*, int, int, int);
extern int __cdecl CheckThing(void*, int);
extern void __cdecl DoThing(void*);
extern void __cdecl FinishThing(void*, int);
int __cdecl Target(void* p) {
    int a = MakeThing(p, 1, 0, 0);
    int b = CheckThing(p, a);
    if (b == 0) return 1;
    DoThing(p);
    FinishThing(p, -2);
    return 2;
}
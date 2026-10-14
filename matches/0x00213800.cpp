struct S_213800 {
    char pad[8];
    int* p;
};
struct B_213800 {
    char pad[4];
    int* p;
};
extern B_213800* __fastcall FUN_00212bb0(void*, S_213800*);
extern void* __cdecl FUN_00219ef0(void*, int*, void*);
extern void __cdecl FUN_00217100(void*, void*, void*);
void __cdecl FUN_00213800(S_213800* s, void* a) {
    B_213800* b = FUN_00212bb0(a, s);
    int* p = s->p;
    void* q = FUN_00219ef0(s, b->p, p - 4);
    ((int*)q)[0] = p[-2];
    ((int*)q)[1] = p[-1];
    int* r = s->p;
    if (r[-2] >= 4 && (((char*)r[-1])[5] & 3) && (((char*)b->p)[5] & 4))
        FUN_00217100(s, b->p, (void*)r[-1]);
    s->p = (int*)((char*)s->p - 16);
}
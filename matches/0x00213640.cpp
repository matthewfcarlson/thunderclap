struct Obj_213640 {
    char pad[8];
    unsigned* out;
};
struct Pair_213640 {
    unsigned a, b;
};
Obj_213640* __fastcall FUN_00212bb0(unsigned, Obj_213640*);
Pair_213640* __cdecl FUN_00219dc0(unsigned, unsigned);
void __cdecl FUN_00213640(Obj_213640* a, unsigned b, unsigned c) {
    Obj_213640* p = FUN_00212bb0(b, a);
    Pair_213640* q = FUN_00219dc0(*(unsigned*)((char*)p + 4), c);
    unsigned* out = a->out;
    out[0] = q->a;
    out[1] = q->b;
    a->out = (unsigned*)((char*)a->out + 8);
}
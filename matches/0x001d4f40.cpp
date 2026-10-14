struct Obj_1d4f40 {
    char pad[0xa0];
    int index;
};
struct Pair_1d4f40 {
    int lo;
    int hi;
};
extern Pair_1d4f40 gTable_1d4f40[];
Pair_1d4f40 __fastcall target(Obj_1d4f40* self) {
    return gTable_1d4f40[self->index];
}
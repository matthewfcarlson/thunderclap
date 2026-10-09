struct Obj {
    char pad[0xa0];
    int index;
};
struct Pair {
    int lo;
    int hi;
};
extern Pair gTable[];
Pair __fastcall target(Obj* self) {
    return gTable[self->index];
}
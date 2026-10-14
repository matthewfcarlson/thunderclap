typedef unsigned int uint;
struct Obj_333970 {
    char pad0[0x1c];
    int mArg;
    char pad20[8];
    uint mCount;
    uint mArray;
};
void __stdcall Work(int, int, void*, int);
void __fastcall FUN_00333970(Obj_333970* self) {
    uint i = 0;
    if (self->mCount <= 0)
        return;
    uint* p = &self->mArray;
    char* q = (char*)self + 0x48;
    do {
        Work(self->mArg, *p, q, *(int*)(q - 4));
        ++i;
        ++p;
        q += 0x44;
    } while (i < self->mCount);
}
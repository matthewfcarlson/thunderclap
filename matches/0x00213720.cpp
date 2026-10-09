struct Thing {
    char pad[8];
    unsigned int* out;
    char pad2[0x34];
};
struct Result {
    int tag;
    char* data;
};
Result* __fastcall FUN_00212bb0(void* other, Thing* self);
void __cdecl FUN_00213720(Thing* self, void* other) {
    Result* r = FUN_00212bb0(other, self);
    unsigned int* src;
    if (r->tag == 6 && r->data[6] == 0)
        src = (unsigned int*)(r->data + 0x10);
    else
        src = (unsigned int*)((char*)self + 0x40);
    unsigned int* dst = self->out;
    dst[0] = src[0];
    dst[1] = src[1];
    self->out += 2;
}
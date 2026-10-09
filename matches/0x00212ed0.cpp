class Thing {
  public:
    char pad[8];
    unsigned int* cursor;
};
extern unsigned int* __fastcall getData(int, Thing*);
void __cdecl target(Thing* self, int a) {
    unsigned int* src = getData(a, self);
    unsigned int* dst = self->cursor;
    dst[0] = src[0];
    dst[1] = src[1];
    self->cursor += 2;
}
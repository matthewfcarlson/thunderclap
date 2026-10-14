class Obj_8ffe0 {
  public:
    char pad[0xc80];
    int count;
};
void __fastcall target(Obj_8ffe0* self) {
    int i = 2;
    if (i < self->count) {
        int* p = (int*)(self->pad + 0xb8);
        do {
            *p = 0;
            ++i;
            p += 0x10;
        } while (i < self->count);
    }
}
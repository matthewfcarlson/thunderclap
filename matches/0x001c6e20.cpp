typedef unsigned int u32_1c6e20;
struct Sub_1c6e20 {
    void clean();
};
void finish(u32_1c6e20);
struct Container_1c6e20 {
    char* begin;
    char* end;
};
void __fastcall target(Container_1c6e20* self) {
    char* p = self->begin;
    if (p) {
        char* e = self->end;
        for (; p != e; p += 0xa8)
            ((Sub_1c6e20*)(p + 4))->clean();
        finish((u32_1c6e20)self->begin);
    }
}
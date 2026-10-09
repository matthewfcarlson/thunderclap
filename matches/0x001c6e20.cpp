typedef unsigned int u32;
struct Sub {
    void clean();
};
void finish(u32);
struct Container {
    char* begin;
    char* end;
};
void __fastcall target(Container* self) {
    char* p = self->begin;
    if (p) {
        char* e = self->end;
        for (; p != e; p += 0xa8)
            ((Sub*)(p + 4))->clean();
        finish((u32)self->begin);
    }
}
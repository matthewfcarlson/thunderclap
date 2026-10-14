typedef unsigned int u32_2a4da0;
struct Item_2a4da0 {
    void Destroy();
};
extern void __cdecl ReleaseBlock(void*);
struct Container_2a4da0 {
    Item_2a4da0* begin;
    Item_2a4da0* end;
};
void __fastcall Target(Container_2a4da0* self) {
    Item_2a4da0* p = self->begin;
    if (p) {
        Item_2a4da0* end = self->end;
        for (; p != end; p = (Item_2a4da0*)((char*)p + 16))
            p->Destroy();
        ReleaseBlock(self->begin);
    }
}
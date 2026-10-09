typedef unsigned int u32;
struct Item { void Destroy(); };
extern void __cdecl ReleaseBlock(void*);
struct Container { Item* begin; Item* end; };
void __fastcall Target(Container* self) {
    Item* p = self->begin;
    if (p) {
        Item* end = self->end;
        for (; p != end; p = (Item*)((char*)p + 16)) p->Destroy();
        ReleaseBlock(self->begin);
    }
}
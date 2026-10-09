struct Item {
    int a, b, c;
};
void __fastcall DestroyItem(Item*);
void __cdecl Finish(Item*);
struct Owner {
    Item* begin;
    Item* end;
};
void __fastcall Target(Owner* self) {
    Item* p = self->begin;
    if (p) {
        Item* e = self->end;
        while (p != e) {
            DestroyItem((Item*)((char*)p + 4));
            p = (Item*)((char*)p + 12);
        }
        Finish(self->begin);
    }
}
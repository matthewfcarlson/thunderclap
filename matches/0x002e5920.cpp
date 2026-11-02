struct Item_2e5920 {
    int a, b, c;
};
extern "C" void __fastcall FUN_002c6d50(Item_2e5920*);
void __cdecl Finish(Item_2e5920*);
struct Owner_2e5920 {
    Item_2e5920* begin;
    Item_2e5920* end;
};
void __fastcall Target(Owner_2e5920* self) {
    Item_2e5920* p = self->begin;
    if (p) {
        Item_2e5920* e = self->end;
        while (p != e) {
            FUN_002c6d50((Item_2e5920*)((char*)p + 4));
            p = (Item_2e5920*)((char*)p + 12);
        }
        Finish(self->begin);
    }
}
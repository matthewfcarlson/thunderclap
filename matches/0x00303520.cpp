struct Item_303520 {
    unsigned int prefix[9];
    float key;
    unsigned int suffix[7];
    void FUN_002f7a90(const Item_303520* other);
};
extern "C" void __cdecl FUN_00303520(void * first, void * second, void * third) {
    Item_303520 temp;
    if (((Item_303520 *)second)->key < ((Item_303520 *)first)->key) {
        temp = *((Item_303520 *)second);
        ((Item_303520 *)second)->FUN_002f7a90(((Item_303520 *)first));
        ((Item_303520 *)first)->FUN_002f7a90(&temp);
    }
    if (((Item_303520 *)third)->key < ((Item_303520 *)second)->key) {
        temp = *((Item_303520 *)third);
        ((Item_303520 *)third)->FUN_002f7a90(((Item_303520 *)second));
        ((Item_303520 *)second)->FUN_002f7a90(&temp);
    }
    if (((Item_303520 *)second)->key < ((Item_303520 *)first)->key) {
        temp = *((Item_303520 *)second);
        ((Item_303520 *)second)->FUN_002f7a90(((Item_303520 *)first));
        ((Item_303520 *)first)->FUN_002f7a90(&temp);
    }
}

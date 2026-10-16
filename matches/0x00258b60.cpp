struct Item {
    char pad[0x78];
    int value;
};
struct Owner {
    char pad[0x20];
    Item* items[1];
};
int __cdecl FUN_00258b60(Owner* p, int index) {
    return p->items[index]->value;
}
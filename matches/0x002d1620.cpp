struct Data {
    char pad[8];
    int divisor;
    float scale;
};
struct Owner {
    char pad[0x1bc];
    Data* data;
};
struct Item {
    char pad[0x19];
    char value;
    char pad2[0x12];
    float amount;
};
void __cdecl FUN_002d1620(int unused, Owner* owner, Item* item) {
    Data* d = owner->data;
    item->value = (char)((int)(item->amount / d->scale) % d->divisor);
}
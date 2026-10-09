struct Item { void Add(int, int); };
struct Owner { char pad[0x40]; int count; void Add(int a, int b); };
void Owner::Add(int a, int b) {
    if (count < 8) {
        Item* item = (Item*)((char*)this + count * 8);
        item->Add(a, b);
        ++count;
    }
}

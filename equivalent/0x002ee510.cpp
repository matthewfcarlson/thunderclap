// STATUS: equivalent (tools/equiv.py level 3: 783 inputs, branch coverage 8/8)
// FUN_002ee510 @ 0x002ee510
struct Item { virtual void slot0(); virtual void slot1(); };
struct Container { char pad[0x3c]; Item **begin; Item **end; void FUN_002ee510(Item *item); };
void Container::FUN_002ee510(Item *item) {
    if (begin == end) return;
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i) {
        if (begin[i] == item) {
            Item **last = end - 1;
            end = last;
            if (begin + i < last) begin[i] = *last;
            item->slot1();
            return;
        }
    }
}
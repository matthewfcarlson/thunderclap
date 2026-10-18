// pure3d::OpaqueTraversal::vfunc_6 @ 0x002a2be0
struct Slot_2a2be0 {
    struct Item_2a2be0* item;      // 0x00
    struct Slot16_2a2be0* part;    // 0x04
    struct Parts* parts;    // 0x08
    int tag;                // 0x0c
};

struct Slot16_2a2be0 {
    int w[4];
};

struct Parts {
    char pad0[0x48];
    Slot16_2a2be0* begin;          // 0x48
    Slot16_2a2be0* end;            // 0x4c
};

struct Item_2a2be0 {
    char pad0[0x40];
    Parts* parts;           // 0x40
    int tag;                // 0x44
};

class OpaqueTraversal {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Item_2a2be0* item, unsigned int index, int unused);
    char pad04[0x18 - 4];
    int count;              // 0x18
    char pad1c[4];
    Slot_2a2be0* slots;            // 0x20
    char pad24[0x2c - 0x24];
    Slot_2a2be0** order;           // 0x2c
};

// Queues part `index` of an item's part list, ignoring indices past the end.
void OpaqueTraversal::vfunc_6(Item_2a2be0* item, unsigned int index, int unused)
{
    if (item->parts == 0)
        return;
    if (index >= (unsigned int)(item->parts->end - item->parts->begin))
        return;
    order[count] = &slots[count];
    slots[count].item = item;
    slots[count].part = &item->parts->begin[index];
    slots[count].parts = item->parts;
    slots[count].tag = item->tag;
    count++;
}

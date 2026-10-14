// STATUS: equivalent (tools/equiv.py level 3: 384 inputs, branch coverage 6/6)
// VScroll::vfunc_15 @ 0x000e26b0
// VScroll: position of the item with the given key: x from the layout origin, y = the item's stored
// value, z from the layout size; all zero when the key is unknown.
struct Vec3 {
    float x, y, z;
};

class Layout {
public:
    char pad0[0x28];
    Vec3* FUN_000f6370(Vec3* out);
};

struct Item {
    int key;
    int pad4;
    float value;
    int padc;
};

struct Frame {
    float savedZ;
    Vec3 first;
    Vec3 second;
};

class VScroll {
public:
    char pad0[0x18];
    Layout layout;
    Item items[0x20];
    int itemCount;

    void FUN_000e26b0(Vec3* out, int key);
};

void VScroll::FUN_000e26b0(Vec3* out, int key)
{
    for (int i = 0; i < itemCount; i++) {
        if (items[i].key == key) {
            Frame f;
            f.savedZ = layout.FUN_000f6370(&f.first)->z;
            float y = items[i].value;
            float x = layout.FUN_000f6370(&f.second)->x;
            out->x = x;
            out->y = y;
            out->z = f.savedZ;
            return;
        }
    }
    out->x = 0;
    out->y = 0;
    out->z = 0;
}

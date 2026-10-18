// VScroll::vfunc_15 @ 0x000e26b0
// VScroll: position of the item with the given key: x from the layout origin, y = the item's stored
// value, z from the layout size; all zero when the key is unknown.
struct Vec3_e26b0 {
    float x, y, z;
};

class Layout_e26b0 {
public:
    char pad0[0x28];
    Vec3_e26b0* FUN_000f6370(Vec3_e26b0* out);
};

struct Item_e26b0 {
    int key;
    int pad4;
    float value;
    int padc;
};

struct Frame_e26b0 {
    float savedZ;
    Vec3_e26b0 first;
    Vec3_e26b0 second;
};

class VScroll {
public:
    char pad0[0x18];
    Layout_e26b0 layout;
    Item_e26b0 items[0x20];
    int itemCount;

    void FUN_000e26b0(Vec3_e26b0* out, int key);
};

void VScroll::FUN_000e26b0(Vec3_e26b0* out, int key)
{
    for (int i = 0; i < itemCount; i++) {
        if (items[i].key == key) {
            Frame_e26b0 f;
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

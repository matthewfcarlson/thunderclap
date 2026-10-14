// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 26/26)
// FUN_002fa290 @ 0x002fa290
extern float DAT_004d2c84;
extern float DAT_004d2c88;
extern float DAT_004d2c8c;
extern float DAT_004d2c90;
extern float DAT_004d2c94;
extern float DAT_004d2c98;

struct Vec3_2fa290 {
    float x, y, z;
};

struct Box_2fa290 {
    float x, y, z;
    bool FUN_002f90c0(Vec3_2fa290* p);
};

struct Matrix {
    char data[0x40];
};

struct Item_2fa290 {
    char pad00[0x8c];
    Matrix xform;               // 0x8c
    char hasXform;              // 0xcc
    char padcd[3];
    int version;                // 0xd0
};

class VisCache;
struct Entry_2fa290;

// temporary built from an item's transform and the cache
struct Temp_2fa290 {
    char data[0x18];
    void FUN_00298530(Matrix* xform, VisCache* cache);
};

struct Entry_2fa290 {
    Item_2fa290* item;                 // 0x00
    int version;                // 0x04
    unsigned short* first;      // 0x08
    unsigned short* last;       // 0x0c
    void FUN_002fa1f0(void* source, Item_2fa290* item);
};

// The dead argument slots double as scratch: the iterator lives in the first one, and the
// temporary is built in the whole block.
union Frame_2fa290 {
    struct {
        Vec3_2fa290 pos;
        Vec3_2fa290 size;
    } in;
    Entry_2fa290* it;
    Temp_2fa290 temp;
};

struct ShortVec {
    unsigned short* begin;
    unsigned short* end;
    unsigned short* cap;
    void FUN_002f9930(unsigned short* pos, int count, unsigned short* src);
};

Entry_2fa290* FUN_002f9460(Entry_2fa290* first, Entry_2fa290* last, Entry_2fa290* dest);

class VisCache {
public:
    void FUN_002fa290(Frame_2fa290 frame, Item_2fa290* item, Entry_2fa290* out);
    void FUN_002f9ed0();

    Vec3_2fa290 lo;                    // 0x00
    Vec3_2fa290 hi;                    // 0x0c
    Box_2fa290 box;                    // 0x18
    Vec3_2fa290 boxMax;                // 0x24
    Entry_2fa290* begin;               // 0x30
    Entry_2fa290* end;                 // 0x34
    Entry_2fa290* cap;                 // 0x38
    char pad3c[4];
    ShortVec shorts;            // 0x40
};

void VisCache::FUN_002fa290(Frame_2fa290 frame, Item_2fa290* item, Entry_2fa290* out)
{
    if (box.FUN_002f90c0(&frame.in.pos)) {
        frame.it = begin;
        if (frame.it != end) {
            for (;;) {
                if (frame.it->item != item) {
                    frame.it++;
                } else {
                    if (frame.it->version == item->version) {
                        out->first = frame.it->first;
                        out->last = frame.it->last;
                        return;
                    }
                    Entry_2fa290* last = end;
                    Entry_2fa290* src = frame.it + 1;
                    if (src != last) {
                        Entry_2fa290* dst = frame.it;
                        do {
                            *dst = *src;
                            src++;
                            dst++;
                        } while (src != last);
                    }
                    end--;
                }
                if (frame.it == end)
                    break;
            }
        }
    } else {
        end = begin;
        shorts.end = shorts.begin;
        boxMax.x = DAT_004d2c90 + frame.in.size.x;
        boxMax.y = frame.in.size.y + DAT_004d2c94;
        boxMax.z = frame.in.size.z + DAT_004d2c98;
        box.x = frame.in.pos.x - DAT_004d2c90;
        box.y = frame.in.pos.y - DAT_004d2c94;
        box.z = frame.in.pos.z - DAT_004d2c98;
        hi.x = DAT_004d2c84 + boxMax.x;
        hi.y = DAT_004d2c88 + boxMax.y;
        hi.z = DAT_004d2c8c + boxMax.z;
        lo.x = box.x - DAT_004d2c84;
        lo.y = box.y - DAT_004d2c88;
        lo.z = box.z - DAT_004d2c8c;
    }

    if (item->hasXform) {
        frame.temp.FUN_00298530(&item->xform, this);
        out->FUN_002fa1f0(&frame.temp, item);
    } else {
        out->FUN_002fa1f0(this, item);
    }

    if (end == cap) {
        FUN_002f9460(begin + 1, end, begin);
        end--;
    }

    unsigned int free = (shorts.cap - shorts.begin) - (shorts.end - shorts.begin);
    int count = out->last - out->first;
    if (free < (unsigned int)count) {
        FUN_002f9ed0();
        free = (shorts.cap - shorts.begin) - (shorts.end - shorts.begin);
        count = out->last - out->first;
        if (free < (unsigned int)count) {
            end = begin;
            shorts.end = shorts.begin;
        }
    }

    unsigned short* oldEnd = shorts.end;
    shorts.FUN_002f9930(oldEnd, out->last - out->first, out->first);

    if (end < cap) {
        Entry_2fa290* slot = end;
        end = slot + 1;
        if (slot)
            *slot = *out;
    }

    unsigned short* newEnd = shorts.end;
    Entry_2fa290* tail = end - 1;
    tail->first = oldEnd;
    tail->last = newEnd;
}

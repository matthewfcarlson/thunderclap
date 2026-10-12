// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 26/26)
// FUN_002fa290 @ 0x002fa290
extern float DAT_004d2c84;
extern float DAT_004d2c88;
extern float DAT_004d2c8c;
extern float DAT_004d2c90;
extern float DAT_004d2c94;
extern float DAT_004d2c98;

struct Vec3 {
    float x, y, z;
};

struct Box {
    float x, y, z;
    bool FUN_002f90c0(Vec3* p);
};

struct Matrix {
    char data[0x40];
};

struct Item {
    char pad00[0x8c];
    Matrix xform;               // 0x8c
    char hasXform;              // 0xcc
    char padcd[3];
    int version;                // 0xd0
};

class VisCache;
struct Entry;

// temporary built from an item's transform and the cache
struct Temp {
    char data[0x18];
    void FUN_00298530(Matrix* xform, VisCache* cache);
};

struct Entry {
    Item* item;                 // 0x00
    int version;                // 0x04
    unsigned short* first;      // 0x08
    unsigned short* last;       // 0x0c
    void FUN_002fa1f0(void* source, Item* item);
};

// The dead argument slots double as scratch: the iterator lives in the first one, and the
// temporary is built in the whole block.
union Frame {
    struct {
        Vec3 pos;
        Vec3 size;
    } in;
    Entry* it;
    Temp temp;
};

struct ShortVec {
    unsigned short* begin;
    unsigned short* end;
    unsigned short* cap;
    void FUN_002f9930(unsigned short* pos, int count, unsigned short* src);
};

Entry* FUN_002f9460(Entry* first, Entry* last, Entry* dest);

class VisCache {
public:
    void FUN_002fa290(Frame frame, Item* item, Entry* out);
    void FUN_002f9ed0();

    Vec3 lo;                    // 0x00
    Vec3 hi;                    // 0x0c
    Box box;                    // 0x18
    Vec3 boxMax;                // 0x24
    Entry* begin;               // 0x30
    Entry* end;                 // 0x34
    Entry* cap;                 // 0x38
    char pad3c[4];
    ShortVec shorts;            // 0x40
};

void VisCache::FUN_002fa290(Frame frame, Item* item, Entry* out)
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
                    Entry* last = end;
                    Entry* src = frame.it + 1;
                    if (src != last) {
                        Entry* dst = frame.it;
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
        Entry* slot = end;
        end = slot + 1;
        if (slot)
            *slot = *out;
    }

    unsigned short* newEnd = shorts.end;
    Entry* tail = end - 1;
    tail->first = oldEnd;
    tail->last = newEnd;
}

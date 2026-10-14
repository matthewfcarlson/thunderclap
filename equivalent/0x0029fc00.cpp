// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0029fc00 @ 0x0029fc00
// FUN_0029fc00 @ 0x0029fc00: advances one entry's countdown; when it expires, re-arms it and re-emits if still valid
struct Region_29fc00 {
    bool FUN_0022d2b0(void *outer, int key);
};

struct Entry_29fc00 {
    char pad00[0x1c];
    int owner;
    int key;
    char pad24[4];
    char box[8];
    char pad30[8];
    char flagged;
    char pad39[3];
    int counter;
    int interval;
    void FUN_0029ea40(int mode);
};

class Tracker_29fc00 {
public:
    char pad00[0x24];
    int owner;
    float FUN_0029dcc0(Region_29fc00 *region, int mode);
    bool FUN_0029fc00(int mode, Region_29fc00 *region, Entry_29fc00 *entry);
};

bool Tracker_29fc00::FUN_0029fc00(int mode, Region_29fc00 *region, Entry_29fc00 *entry)
{
    if (entry == 0)
        return false;

    entry->counter = entry->counter - 1;
    if (entry->counter > 0) {
        entry->FUN_0029ea40(mode);
        return true;
    }

    entry->counter = entry->interval + entry->counter;
    if (region->FUN_0022d2b0(&entry->box, entry->key)) {
        if (owner == entry->owner) {
            if (entry->flagged) {
                float v = FUN_0029dcc0(region, 8);
                if (!(v <= 0.0f))
                    return false;
            }
            entry->FUN_0029ea40(mode);
            return true;
        }
    }
    return false;
}

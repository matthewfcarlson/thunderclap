// STATUS: equivalent (tools/equiv.py level 3: 11988 inputs, branch coverage 14/14)
// FUN_001fa3a0 @ 0x001fa3a0
// cl-flags: /GS
#include "decls/address.h"
int __cdecl FUN_00267760(char *buf, int size, const char *fmt);

struct S8_1fa3a0 {
    int a;
    int b;
    void FUN_0027af30(const S8_1fa3a0 *src);
    void FUN_0027b040(const char *name);
};

/* 16-byte by-value argument; only the first ten bytes are copied. Overlays a record's
   name and two flag bytes, which are re-read after the name copy. */
struct SlotKey_1fa3a0 {
    S8_1fa3a0 name;
    char flagA;
    char flagB;
    char pad[6];
    SlotKey_1fa3a0(const SlotKey_1fa3a0 &src) {
        name.FUN_0027af30(&src.name);
        flagA = src.flagA;
        flagB = src.flagB;
    }
};

struct Event_1fa3a0 {
    int words[24];
    void FUN_001ca040(const void *a, const void *b);
};

struct Listener_1fa3a0 {
    void FUN_001cbc20(Event_1fa3a0 *ev);
};

struct World {
    char pad00[0x30];
    Listener_1fa3a0 *listener;
};


struct Record_1fa3a0 {
    char pad00[8];
    int field08;
    char label[0x20];
    char pad2c[4];
    S8_1fa3a0 name;
    unsigned char flagA;
    unsigned char flagB;
    char pad3a[6];
    int f40, f44, f48, f4c;
    unsigned char f50;
    unsigned char f51;
    unsigned short f52;
    char pad54[4];
    void FUN_001f91b0(const Record_1fa3a0 *src);
};

struct Channel {
    char flag;
    char pad[0x27];
};

class Mixer {
public:
    char pad000[0x41c];
    char settings[0x484 - 0x41c];
    Channel channels[1];
    char pad4ac[0x6e0 - 0x4ac - 0x28 + 0x28];
    int channelCount;
    char pad6e4[4];
    Record_1fa3a0 records[16];
    int recordCount;

    void FUN_001f9fc0(SlotKey_1fa3a0 key);
    void FUN_001fa3a0(int index);
};

void Mixer::FUN_001fa3a0(int index)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */

    if (index >= 0 && index < recordCount) {
        for (int i = 0; i < channelCount; i++) {
            if (channels[i].flag) {
                Record_1fa3a0 *r = &records[index];
                r->flagB = (unsigned char)i;
                FUN_001f9fc0(*(SlotKey_1fa3a0 *)&r->name);
            }
        }
        Record_1fa3a0 *r = &records[index];
        r->flagB = 0xff;

        Listener_1fa3a0 *l = DAT_004dd700->listener;
        if (l) {
            Event_1fa3a0 ev;
            ev.FUN_001ca040(settings, r->label);
            l->FUN_001cbc20(&ev);
        }

        r->field08 = 0;
        FUN_00267760(r->label, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
        r->f40 = 0;
        r->f44 = 0;
        r->f48 = 0;
        r->f4c = 0;
        r->flagA = 0xff;
        r->name.FUN_0027b040("");
        r->flagB = 0xff;
        r->f50 = 0;
        r->f51 = 1;
        r->f52 = 0xffff;
        if (index != recordCount - 1)
            r->FUN_001f91b0(&records[recordCount - 1]);
        recordCount--;
    }
}

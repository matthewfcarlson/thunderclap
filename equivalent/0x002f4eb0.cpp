// STATUS: equivalent (tools/equiv.py level 3: 275 inputs, branch coverage 30/30)
// physics::ExportInfoLoader::vfunc_5 @ 0x002f4eb0
#include "compat/ptr.h"
#include "gen/physics.h"
#include "decls/data/engine/physics.h"

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int memcmp(const void* a, const void* b, unsigned int n);

struct Stream_2f4eb0 {
    char pad0[0xc];
    char open;
    char pad1;
    char binary;
    char FUN_002647e0(void* dest, unsigned count, unsigned size, int flag);
};

struct Reader_2f4eb0 {
    char pad[0x284];
    Stream_2f4eb0* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

void FUN_002ecb70();
void FUN_002ecb90(int units);

struct Frame_2f4eb0 {
    char pad[2];
    unsigned char len1;
    unsigned char len2;
    char unitsName[0x20];
    char tag[0x80];
    char msg[0x64];
};

void physics::ExportInfoLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int a3) { hulk_intptr a0 = (hulk_intptr)__p0; hulk_intptr a1 = (hulk_intptr)__p1; Reader_2f4eb0 * r = (Reader_2f4eb0 *)__p2;

    Frame_2f4eb0 f;
    int units;
    bool found;

    r->stream->FUN_002647e0(&f.len1, 1, 1, 1);
    unsigned n = f.len1;
    r->stream->FUN_002647e0(f.tag, n, 1, 1);
    f.tag[n] = 0;
    found = false;
    while (r->FUN_002669f0() && !found) {
        r->FUN_00266a30();
        r->stream->FUN_002647e0(&f.len1, 1, 1, 1);
        n = f.len1;
        r->stream->FUN_002647e0(f.tag, n, 1, 1);
        f.tag[n] = 0;
        if (memcmp(f.tag, "UI Units", 9) == 0) {
            r->stream->FUN_002647e0(&f.len2, 1, 1, 1);
            n = f.len2;
            r->stream->FUN_002647e0(f.unitsName, n, 1, 1);
            f.unitsName[n] = 0;
            found = true;
        }
        r->FUN_00266be0();
    }

    if (memcmp(f.unitsName, "Millimeters", 12) == 0)
        units = 0;
    else if (memcmp(f.unitsName, "Centimeters", 12) == 0)
        units = 1;
    else if (memcmp(f.unitsName, "Meters", 7) == 0)
        units = 2;
    else if (memcmp(f.unitsName, "Kilometers", 11) == 0)
        units = 3;
    else if (memcmp(f.unitsName, "Inches", 7) == 0)
        units = 4;
    else if (memcmp(f.unitsName, "Feet", 5) == 0)
        units = 5;
    else if (memcmp(f.unitsName, "Yards", 6) == 0)
        units = 6;
    else if (memcmp(f.unitsName, "Miles", 6) == 0)
        units = 7;
    else
        units = 8;

    if (DAT_00554c0c == 1) {
        if (DAT_004d2880 == units)
            return;
        if (!(*(char*)&DAT_00554c0d)) {
            sprintf(f.msg, "UI Units used in p3d file, %s, conflict with current settings", f.unitsName);
            return;
        }
        FUN_002ecb70();
    }
    FUN_002ecb90(units);
}

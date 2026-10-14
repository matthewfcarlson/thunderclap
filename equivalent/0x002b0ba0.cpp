// STATUS: equivalent (tools/equiv.py level 3: 24 inputs, branch coverage 12/12)
// FUN_002b0ba0 @ 0x002b0ba0
extern "C" double fabs(double);

struct Sink_2b0ba0 {
    void FUN_002d0e20(void *slot, float value);
};

struct Channel {
    char pad[0x14];
    void **slots;
};

struct Rec_2b0ba0 {
    char active;
    char pad0[3];
    int slotA;
    int slotB;
    float valueA;
    float valueB;
    float valueC;
};

struct Table_2b0ba0 {
    char pad[0x10];
    Channel **channels;
};

struct Blender_2b0ba0 {
    char pad0[0x10];
    Table_2b0ba0 *table;
    char pad1[0x20 - 0x14];
    Rec_2b0ba0 *begin;
    Rec_2b0ba0 *end;

    void FUN_002b0ba0(Sink_2b0ba0 *sink);
};

void Blender_2b0ba0::FUN_002b0ba0(Sink_2b0ba0 *sink)
{
    for (unsigned i = 0; i < (unsigned)(end - begin); i++) {
        Channel *ch = table->channels[i];
        Rec_2b0ba0 *r = &begin[i];
        if (r->active) {
            float v = r->valueA;
            if (!((float)fabs(v) < 0.01f))
                sink->FUN_002d0e20(ch->slots[r->slotA], v);
            v = r->valueB;
            if (!((float)fabs(v) < 0.01f))
                sink->FUN_002d0e20(ch->slots[r->slotB], v);
        } else {
            float v = r->valueC;
            if (!((float)fabs(v) < 0.01f))
                sink->FUN_002d0e20(ch->slots[r->slotA], v);
        }
    }
}

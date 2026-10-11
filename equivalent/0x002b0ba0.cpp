// STATUS: equivalent (tools/equiv.py level 3: 24 inputs, branch coverage 12/12)
// FUN_002b0ba0 @ 0x002b0ba0
extern "C" double fabs(double);

struct Sink {
    void FUN_002d0e20(void *slot, float value);
};

struct Channel {
    char pad[0x14];
    void **slots;
};

struct Rec {
    char active;
    char pad0[3];
    int slotA;
    int slotB;
    float valueA;
    float valueB;
    float valueC;
};

struct Table {
    char pad[0x10];
    Channel **channels;
};

struct Blender {
    char pad0[0x10];
    Table *table;
    char pad1[0x20 - 0x14];
    Rec *begin;
    Rec *end;

    void FUN_002b0ba0(Sink *sink);
};

void Blender::FUN_002b0ba0(Sink *sink)
{
    for (unsigned i = 0; i < (unsigned)(end - begin); i++) {
        Channel *ch = table->channels[i];
        Rec *r = &begin[i];
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

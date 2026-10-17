// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 8/8)
// FUN_000352b0 @ 0x000352b0
struct Output { unsigned int x,y,z; };
struct Entry { char pad[0x30]; Output value; char rest[0x40-0x30-12]; };
struct Container { char pad0[12]; unsigned int count; char pad1[12]; Entry* entries; };
struct Selection { char pad[0x20]; unsigned int index; };
struct Object { char pad[0x11c]; Selection* selection; Container* container; bool FUN_000352b0(Output* out); };
bool Object::FUN_000352b0(Output* out) {
    Container* c = container;
    if (!c) return false;
    Selection* s = selection;
    if (!s) return false;
    unsigned int i = s->index;
    if (i == 0xffff || i >= c->count) return false;
    out->x = c->entries[i].value.x;
    out->y = c->entries[i].value.y;
    out->z = c->entries[i].value.z;
    return true;
}
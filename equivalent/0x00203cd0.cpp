// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// FUN_00203cd0 @ 0x00203cd0
struct Id { int a, b, c; };
struct Rec { char pad[0x54]; short value; };
struct Registry {
    Rec* FUN_001c8060(Id* id, void* tag);
    Rec* FUN_001c81a0(Id* id);
};
struct Holder { char pad[4]; Registry* reg; };
struct Cursor { bool FUN_00059a50(Id* out); };
struct Source { char pad[0x10]; Cursor* cursor; };
struct Part { char pad[0x124]; Source* src; };
struct Link { char pad[0x20]; Part* part; };
struct Group { char pad[0xc]; Link* link; };
extern char DAT_004e5a88[];
Holder* FUN_001c3d90();
struct Actor {
    char pad0[0x588]; Group* group;
    char pad1[0xaf8 - 0x58c]; int busy;
    int GetValue();
};
int Actor::GetValue() {
    if (busy > 0) return busy;
    Link* l = group->link;
    if (!l) return 0;
    Part* part = l->part;
    if (!part) return 0;
    Source* src = part->src;
    if (!src) return 0;
    Registry* reg = ((Registry*)FUN_001c3d90()->reg);
    Id id;
    if (!src->cursor->FUN_00059a50(&id)) return 0;
    Rec* r = reg->FUN_001c8060(&id, DAT_004e5a88);
    if (!r) r = reg->FUN_001c81a0(&id);
    if (!r) return 0;
    return r->value;
}

// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// FUN_00203cd0 @ 0x00203cd0
struct Id_203cd0 { int a, b, c; };
struct Rec_203cd0 { char pad[0x54]; short value; };
struct Registry_203cd0 {
    Rec_203cd0* FUN_001c8060(Id_203cd0* id, void* tag);
    Rec_203cd0* FUN_001c81a0(Id_203cd0* id);
};
struct Holder_203cd0 { char pad[4]; Registry_203cd0* reg; };
struct Cursor_203cd0 { bool FUN_00059a50(Id_203cd0* out); };
struct Source_203cd0 { char pad[0x10]; Cursor_203cd0* cursor; };
struct Part_203cd0 { char pad[0x124]; Source_203cd0* src; };
struct Link_203cd0 { char pad[0x20]; Part_203cd0* part; };
struct Group_203cd0 { char pad[0xc]; Link_203cd0* link; };
extern char DAT_004e5a88[];
Holder_203cd0* FUN_001c3d90();
struct Actor_203cd0 {
    char pad0[0x588]; Group_203cd0* group;
    char pad1[0xaf8 - 0x58c]; int busy;
    int GetValue();
};
int Actor_203cd0::GetValue() {
    if (busy > 0) return busy;
    Link_203cd0* l = group->link;
    if (!l) return 0;
    Part_203cd0* part = l->part;
    if (!part) return 0;
    Source_203cd0* src = part->src;
    if (!src) return 0;
    Registry_203cd0* reg = ((Registry_203cd0*)FUN_001c3d90()->reg);
    Id_203cd0 id;
    if (!src->cursor->FUN_00059a50(&id)) return 0;
    Rec_203cd0* r = reg->FUN_001c8060(&id, DAT_004e5a88);
    if (!r) r = reg->FUN_001c81a0(&id);
    if (!r) return 0;
    return r->value;
}

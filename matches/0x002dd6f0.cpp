typedef unsigned int u32;
struct Obj {
    char pad0[0x4c];
    u32 field4c;
    u32 field50;
    char pad54[8];
    u32 field5c;
    char pad60[0xe4];
    u32 field144;
};
extern void Report(Obj*, const char*);
void Target(Obj* p, u32 value, void* fn) {
    p->field5c = value;
    if (fn)
        p->field50 = (u32)fn;
    else
        p->field50 = 0x02dd6b0;
    if (p->field4c) {
        p->field4c = 0;
        Report(p, "It's an error to set both read_data_fn and write_data_fn in the ");
        Report(p, "same structure.  Resetting write_data_fn to NULL.");
    }
    p->field144 = 0;
}
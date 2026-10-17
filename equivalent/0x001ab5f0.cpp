// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// hulkfight::scenario::Event_FirstTimeCondition::vfunc_6 @ 0x001ab5f0
struct Descriptor { int value; }; extern Descriptor DAT_00494b44; extern Descriptor DAT_004c13d0;
struct EventData { char pad[4]; int kind; char gap[0x50]; unsigned char flag; };
struct Params { EventData* FUN_001d03c0(); };
extern Params* __cdecl FUN_00344e74(void*, int, Descriptor*, Descriptor*, int);
namespace hulkfight { namespace scenario {
struct Event_FirstTimeCondition { char pad[12]; unsigned char flag; bool vfunc_6(void*, void*, void*); };
bool Event_FirstTimeCondition::vfunc_6(void* unused, void* params, void* extra) {
    Params* p = FUN_00344e74(params, 0, &DAT_00494b44, &DAT_004c13d0, 0);
    if (!p) return false;
    EventData* data = p->FUN_001d03c0();
    return data->kind == 0x11 && data->flag == flag;
}
}}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/11)
// FUN_001b0470 @ 0x001b0470
struct Item {
    int FUN_001d72e0();
    int FUN_001d64a0();
};
struct State {
    char reserved[0x14];
    int value;
};
struct Actor {
    char reserved[0x11c];
    State* state;
    float FUN_001b0310();
    void FUN_00043ae0(int, int, float, int, float, int, int, int, int);
};
extern bool __cdecl FUN_00044500(int);
extern unsigned char DAT_001b0590[10];

// The case-selection bytes follow five branch addresses in the dispatch data.
struct DispatchData {
    unsigned char* branches[5];
    unsigned char cases[10];
};

// equiv-conv: FUN_001b0470 eax ecx stack
float __cdecl FUN_001b0470(Item* item, Actor* self, int argument)
{
    float result = self->FUN_001b0310();
    int identifier = item->FUN_001d72e0();
    unsigned int type = (unsigned int)item->FUN_001d64a0() - 2;
    if (type <= 9) {
        const DispatchData* dispatch = reinterpret_cast<const DispatchData*>(
            DAT_001b0590 - 5 * sizeof(unsigned char*));
        unsigned char* branch = dispatch->branches[DAT_001b0590[type]];
        const unsigned char* origin = reinterpret_cast<const unsigned char*>(dispatch);
        float angle = 90.0f;
        if (branch == origin - 0xa5) {
            angle = FUN_00044500(self->state->value) ? 10.0f : 90.0f;
        } else if (branch == origin - 0x41) {
            angle = FUN_00044500(self->state->value) ? 90.0f : 100.0f;
        } else if (branch == origin - 0x0a) {
            return result;
        }
        self->FUN_00043ae0(identifier, argument, angle, 0, result, 0, 0, 1, 0);
    }
    return result;
}
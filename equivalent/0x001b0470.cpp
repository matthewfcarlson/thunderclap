// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 11/11)
// FUN_001b0470 @ 0x001b0470
// FUN_001b0470 @ 0x001b0470
struct Item_1b0470 {
    int FUN_001d72e0();
    int FUN_001d64a0();
};
struct State_1b0470 {
    char reserved[0x14];
    int value;
};
struct Actor_1b0470 {
    char reserved[0x11c];
    State_1b0470* state;
    float FUN_001b0310();
    void FUN_00043ae0(int, int, float, int, float, int, int, int, int);
};
// equiv-conv: FUN_001b0310 esi edi
float FUN_001b0310(Actor_1b0470 *self, Item_1b0470 *item);
extern bool __cdecl FUN_00044500(int);

// equiv-conv: FUN_001b0470 eax ecx stack
float __cdecl FUN_001b0470(Item_1b0470* item, Actor_1b0470* self, int argument)
{
    float result = FUN_001b0310(self, item);
    int identifier = item->FUN_001d72e0();
    unsigned int type = (unsigned int)item->FUN_001d64a0() - 2;
    if (type <= 9) {
        float angle = 90.0f;
        switch (type) {
        case 0: case 4:
            angle = FUN_00044500(self->state->value) ? 10.0f : 90.0f;
            break;
        case 2: case 9:
            angle = FUN_00044500(self->state->value) ? 90.0f : 100.0f;
            break;
        case 6: case 7:
            return result;
        }
        self->FUN_00043ae0(identifier, argument, angle, 0, result, 0, 0, 1, 0);
    }
    return result;
}

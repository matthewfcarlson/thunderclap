// STATUS: equivalent (tools/equiv.py level 3: 2772 inputs, branch coverage 8/8)
// FUN_001b4060 @ 0x001b4060
typedef unsigned int uint;
extern uint DAT_004c39e8, DAT_004c39ec, DAT_004c39f0, DAT_004c39f4;
extern uint DAT_004c3a08, DAT_004c3a0c, DAT_004c3a10, DAT_004c3a14, DAT_004c3a18, DAT_004c3a1c, DAT_004c3a20, DAT_004c3a24;
struct State { char pad[0x58]; uint firstLow, firstHigh, secondLow, secondHigh; };
struct Link { char pad[0x74]; State* state; };
struct Input { char pad[0x12c]; Link* primary; Link* secondary; };
struct Manager { void FUN_002ee6b0(State* state); };
struct Owner { char pad[8]; Manager* manager; bool FUN_001b4060(Input* input); };
bool Owner::FUN_001b4060(Input* input) {
    if (!input->primary) return false;
    State* primary = input->primary->state;
    if (!primary) return false;
    primary->firstLow = DAT_004c39f0;
    primary->firstHigh = DAT_004c39f4;
    primary->secondLow = DAT_004c39f0 | DAT_004c3a18 | DAT_004c39e8 | DAT_004c3a10 | DAT_004c3a20;
    primary->secondHigh = DAT_004c39f4 | DAT_004c3a1c | DAT_004c39ec | DAT_004c3a14 | DAT_004c3a24;
    State* secondary = 0;
    if (input->secondary) {
        secondary = input->secondary->state;
        secondary->firstLow = DAT_004c3a08;
        secondary->firstHigh = DAT_004c3a0c;
        secondary->secondLow = DAT_004c39e8;
        secondary->secondHigh = DAT_004c39ec;
    }
    manager->FUN_002ee6b0(primary);
    if (secondary) manager->FUN_002ee6b0(secondary);
    return true;
}

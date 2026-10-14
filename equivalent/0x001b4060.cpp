// STATUS: equivalent (tools/equiv.py level 3: 2772 inputs, branch coverage 8/8)
// FUN_001b4060 @ 0x001b4060
typedef unsigned int uint;
extern uint DAT_004c39e8, DAT_004c39ec, DAT_004c39f0, DAT_004c39f4;
extern uint DAT_004c3a08, DAT_004c3a0c, DAT_004c3a10, DAT_004c3a14, DAT_004c3a18, DAT_004c3a1c, DAT_004c3a20, DAT_004c3a24;
struct State_1b4060 { char pad[0x58]; uint firstLow, firstHigh, secondLow, secondHigh; };
struct Link_1b4060 { char pad[0x74]; State_1b4060* state; };
struct Input_1b4060 { char pad[0x12c]; Link_1b4060* primary; Link_1b4060* secondary; };
struct Manager_1b4060 { void FUN_002ee6b0(State_1b4060* state); };
struct Owner_1b4060 { char pad[8]; Manager_1b4060* manager; bool FUN_001b4060(Input_1b4060* input); };
bool Owner_1b4060::FUN_001b4060(Input_1b4060* input) {
    if (!input->primary) return false;
    State_1b4060* primary = input->primary->state;
    if (!primary) return false;
    primary->firstLow = DAT_004c39f0;
    primary->firstHigh = DAT_004c39f4;
    primary->secondLow = DAT_004c39f0 | DAT_004c3a18 | DAT_004c39e8 | DAT_004c3a10 | DAT_004c3a20;
    primary->secondHigh = DAT_004c39f4 | DAT_004c3a1c | DAT_004c39ec | DAT_004c3a14 | DAT_004c3a24;
    State_1b4060* secondary = 0;
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

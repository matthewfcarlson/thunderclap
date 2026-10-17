// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001dd8e0 @ 0x001dd8e0
struct LinkedObject { char pad[0x14d]; unsigned char enabled; };
struct Entry { char pad0[0x18]; LinkedObject* linked; char pad1[6]; short stateIndex; char pad2[4]; };
struct State { char pad[0x10]; unsigned char flags; char remainder[3]; };
struct Controller {
    char pad0[0x608];
    Entry entries[0x800];
    State states[1];
    void FUN_001dd8e0(int index, unsigned char enabled);
};
void Controller::FUN_001dd8e0(int index, unsigned char enabled) {
    if (index < 0 || index >= 0x800) return;
    Entry& entry = entries[index];
    State& state = states[entry.stateIndex];
    if (enabled) state.flags |= 0x20;
    else state.flags &= 0xdf;
    if ((state.flags & 1) && entry.linked)
        entry.linked->enabled = enabled;
}
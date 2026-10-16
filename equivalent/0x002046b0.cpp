// STATUS: equivalent (tools/equiv.py level 3: 702 inputs, branch coverage 12/12)
// FUN_002046b0 @ 0x002046b0
struct Record { char pad[0x56]; short value; };
struct Lookup { Record* FUN_001c7f10(int index); };
struct Provider { char pad[4]; Lookup* lookup; };
struct Game { char pad[0x5a4]; unsigned char states[0x400]; Provider* FUN_001c3d90(); bool FUN_002046b0(int value); };
bool Game::FUN_002046b0(int value) {
    Lookup* lookup = FUN_001c3d90()->lookup;
    for (int i = 0; i < 0x400; ++i) {
        unsigned char state = states[i];
        if (state == 1 || state == 3 || state == 2) {
            Record* record = lookup->FUN_001c7f10(i);
            if (record && record->value == value) return true;
        }
    }
    return false;
}
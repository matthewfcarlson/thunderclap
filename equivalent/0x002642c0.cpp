// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002642c0 @ 0x002642c0
struct Controller {
    char pad0[0x1c];
    unsigned int selected;
    char pad20[0x8];
    char* currentBuffer;
    unsigned int position;
    unsigned int limit;
    unsigned int capacity;
    void FUN_002640f0();
    void FUN_00264050(char* buffer);
    void FUN_002642c0();
};
extern char DAT_004e7c28[0x40000];
void Controller::FUN_002642c0() {
    FUN_002640f0();
    unsigned int next = selected == 0;
    position = 0;
    limit = capacity;
    currentBuffer = DAT_004e7c28 + next * 0x20000;
    selected = next;
    FUN_00264050(DAT_004e7c28 + (next == 0) * 0x20000);
}
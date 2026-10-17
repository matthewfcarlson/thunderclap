// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/10, incomplete)
// FUN_001b6e00 @ 0x001b6e00
extern float DAT_00405d2c;
struct Entry { int id; float time; };
struct Holder { Entry entries[3]; void FUN_001b6e00(int id); };
void Holder::FUN_001b6e00(int id) {
    float oldest = DAT_00405d2c;
    int selected = -1;
    for (int i = 0; i < 3; ++i) {
        if (entries[i].id == 0) {
            selected = i;
            break;
        }
        if (oldest > entries[i].time) {
            oldest = entries[i].time;
            selected = i;
        }
    }
    if (selected != -1) {
        entries[selected].id = id;
        entries[selected].time = 0.25f;
    }
}
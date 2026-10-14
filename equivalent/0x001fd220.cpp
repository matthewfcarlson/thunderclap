// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 15/16, incomplete)
// FUN_001fd220 @ 0x001fd220
struct S8_1fd220 {
    int a;
    int b;
    void FUN_0027af30(char* p);
};

struct Entry_1fd220 {
    int count;
    char* data;
};

struct Slot_1fd220 {
    char pad[0x418];
    int active;
    char pad2[0xc70 - 0x41c];
    void FUN_001f8670(S8_1fd220 s);
};

class Obj_1fd220 {
public:
    void run(int id);
    char p0[0x214];
    Entry_1fd220* lists[6];
    int* ids;
    int pad230;
    char* slots;
};

void Obj_1fd220::run(int id)
{
    int idx;
    for (idx = 0; idx < 20; idx++) {
        if (ids[idx] == id)
            break;
    }
    if (idx >= 20)
        return;

    ids[idx] = -1;
    for (int off = 0; off < 0x6380; off += 0xc70) {
        Slot_1fd220* slot = (Slot_1fd220*)(slots + off);
        if (*(int*)(slots + off + 0x418) == 0)
            continue;
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < lists[k][idx].count; i++) {
                S8_1fd220 s;
                s.FUN_0027af30(lists[k][idx].data + i * 0x40 + 8);
                ((Slot_1fd220*)(slots + off))->FUN_001f8670(s);
            }
        }
    }
    for (int k = 0; k < 6; k++)
        lists[k][idx].count = 0;
}

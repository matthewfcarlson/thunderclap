// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 10/10)
// FUN_003006e0 @ 0x003006e0
// FUN_003006e0: update every active object, then every object once more
struct Obj_3006e0 {
    char data[0x6c];
    void FUN_002ff3f0(int arg);
};

class Group_3006e0 {
public:
    Obj_3006e0 *objs;
    char pad04[4];
    int *begin;
    int *end;
    char pad10[0x20];
    void *cursor;
    char pad34[0x2198 - 0x34];
    char active;
    char pad2199[3];
    int param;

    void FUN_003005e0(int index, int arg);
    void FUN_002ff0c0(int index);
    void FUN_003006e0(int arg);
};

void Group_3006e0::FUN_003006e0(int arg)
{
    unsigned int i;
    for (i = 0; i < (unsigned int)(end - begin); i++) {
        FUN_003005e0(begin[i], arg);
        if (active) {
            cursor = (char *)&objs[i] + 0x40;
            FUN_002ff0c0(begin[i]);
        }
    }
    for (i = 0; i < (unsigned int)(end - begin); i++)
        objs[begin[i]].FUN_002ff3f0(param);
}

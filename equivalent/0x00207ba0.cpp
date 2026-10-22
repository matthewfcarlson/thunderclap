// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 41/42, incomplete)
// FUN_00207ba0 @ 0x00207ba0
struct Entity {
    char pad0[9];
    char flag9;
    char pad1[0x58 - 0xa];
    int f58;
};
struct Registry_207ba0 {
    Entity* FUN_001c7f10(int id);
};
struct Manager_207ba0 {
    char pad0[4];
    Registry_207ba0* reg;
};
extern Manager_207ba0* FUN_001c3d90();
extern int FUN_00267f80();

struct CWorldStreamManager_207ba0 {
    char pad0[0x5a4];
    char kind[0x400];
    char pad1[0x9a8 - 0x9a4];
    int slotCount;
    int slotId[20];
    int slotVal[20];
    int idCount;
    int ids[39];
    void* cur;
    char pad5[0xaf2 - 0xaf0];
    char flagF2;
    char flagF3;
    char padF4;
    char flagF5;
    char pad6[0xafc - 0xaf6];
    int stamp;

    int FUN_00203bb0();
    int FUN_00204ad0(int count, int* list);
    int FUN_00204c10(int a);
    void FUN_00203e30(void* p);
    void FUN_00207410();
    void FUN_00207080(int a);
    char FUN_00207580(int id, int flag);
    void FUN_00207ba0();
};

void CWorldStreamManager_207ba0::FUN_00207ba0()
{
    stamp = FUN_00267f80();
    flagF5 = 1;
    for (int i = 0; i < idCount; i++) {
        int id = ids[i];
        Entity* e = FUN_001c3d90()->reg->FUN_001c7f10(id);
        e->f58 = 0;
        e->flag9 = 1;
        if (id >= 0 && id < 0x400) {
            char k = kind[id];
            if (k == 1 || k == 3) continue;
            if (cur != 0 && flagF2 == 0 && flagF3 == 0) {
                if (FUN_00203bb0() == id) continue;
            }
        }
        bool useFirst = true;
        int first = FUN_00204ad0(idCount, ids);
        int second = FUN_00204c10(0);
        int sel = first;
        if (second > 0) {
            int j = 0;
            bool found = false;
            while (j < idCount) {
                if (id == ids[j]) { found = true; break; }
                j++;
            }
            if (!found) {
                useFirst = false;
                sel = second;
            }
        }
        bool setId = (kind[id] != 2);
        slotVal[slotCount] = useFirst ? sel : -1;
        slotId[slotCount] = setId ? id : -1;
        slotCount = slotCount + 1;
        if (cur != 0) {
            FUN_00203e30(cur);
            FUN_00207410();
        }
        if (sel > 0) {
            FUN_00207080(sel);
        }
        if (FUN_00207580(id, 1) == 0) {
            slotId[slotCount] = -1;
        }
    }
    stamp = 0;
}

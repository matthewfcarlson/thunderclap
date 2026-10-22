// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 18/18)
// FUN_002080b0 @ 0x002080b0
#include "decls/address.h"
class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
};

class Slot_2080b0 {
public:
    virtual void v0();
    virtual void v1();
    void FUN_002660a0(int a);
    void FUN_002665a0();
};

class Ent_2080b0 {
public:
    char pad[0x31];
    char flag31;
    void FUN_001b90b0();
};

class EntList_2080b0 { public: Ent_2080b0 *FUN_00086290(); };
class Input_2080b0 {
public:
    int FUN_000d6f50();
    void FUN_000d7030(int v);
};
class World;
class Res_2080b0 { public: void FUN_0009a400(World *g); };

class World {
public:
    char pad0[8];
    Res_2080b0 *res;
    char pad0c[0x30];
    Input_2080b0 *input;
    char pad40[0x14];
    EntList_2080b0 *ents;
};


class CWorldStreamManager_2080b0;
class Aux_2080b0 { public: int FUN_00266710(); };

class CWorldStreamManager_2080b0 {
public:
    char pad0[0x578];
    Slot_2080b0 *slots[3];
    char pad584[0x9a4 - 0x584];
    int mask;
    char pad9a8[0xaec - 0x9a8];
    Aux_2080b0 *aux;
    char af0;
    char af1;
    char af2;
    char af3;
    void FUN_00203e30(Aux_2080b0 *a);
    void FUN_00207410();
    void FUN_00207d80();
    void FUN_002080b0();
};

void CWorldStreamManager_2080b0::FUN_002080b0()
{
    if (!af1)
        return;
    DAT_0052c2a8->v91();
    DAT_004dd700->res->FUN_0009a400(DAT_004dd700);
    DAT_004dd700->ents->FUN_00086290()->flag31 = 0;
    DAT_004dd700->ents->FUN_00086290()->FUN_001b90b0();
    int in = DAT_004dd700->input->FUN_000d6f50();
    DAT_004dd700->input->FUN_000d7030(mask | in);
    if (af3 && aux) {
        int r = aux->FUN_00266710();
        af0 = 1;
        if (r != 3)
            FUN_00203e30(aux);
        FUN_00207410();
    }
    af3 = 0;
    DAT_0052c2a8->v91();
    if (slots[2])
        slots[2]->FUN_002665a0();
    DAT_0052c2a8->v91();
    if (slots[1])
        slots[1]->FUN_002665a0();
    DAT_0052c2a8->v91();
    if (slots[0])
        slots[0]->FUN_002665a0();
    for (int i = 0; i < 3; i++) {
        slots[i]->FUN_002660a0(0);
        if (slots[i]) {
            slots[i]->v1();
            slots[i] = 0;
        }
    }
    FUN_00207d80();
    af1 = 0;
}

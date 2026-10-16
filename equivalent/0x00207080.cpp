// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00207080 @ 0x00207080
#include "decls/data/game/global.h"

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);

class Locator {
public:
    virtual void v0();
};

class Locator91 : public Locator {
public:
    virtual void v1();
};

struct Marker_207080 {
    void FUN_00204f00();
};

struct Entry_207080 {
    char pad0[0x56];
    short id;               // 0x56
};

struct Index_207080 {
    Entry_207080 *FUN_001c7f10(int key);
};

struct Manager_207080 {
    char pad0[4];
    Index_207080 *index;           // 0x04
};

Manager_207080 *FUN_001c3d90();

class Region;
extern class Services_207080 *DAT_0052c2a8;

class Services_207080 {
public:
    virtual void v0();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90();
    virtual void v91();
};

class District_207080 {
public:
    char pad0[0x24];
    char name[0x570 - 0x24];    // 0x24
    int ids[2];                 // 0x570
    bool FUN_002046b0(int id);
    void FUN_00206a40(int id);
    Marker_207080 *FUN_00204540(const char *label);
    void FUN_00205860(int id);
    void FUN_00207080(int id);
};

void District_207080::FUN_00207080(int id)
{
    struct Frame {
        char label[0x100];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    DAT_0052c2a8->v91();
    _sprintf(fr.label, "%s_r%03d", name, id);
    FUN_00206a40(id);
    if ((*(char*)&DAT_004c91d8) != 0)
        FUN_00204540(fr.label)->FUN_00204f00();
    int room = FUN_001c3d90()->index->FUN_001c7f10(id)->id;
    if (!FUN_002046b0(room))
        FUN_00205860(room);
    __security_check_cookie(fr.cookie);
}

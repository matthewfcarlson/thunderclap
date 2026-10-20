// pure3d::TranslucentTraversal::vfunc_4 @ 0x002a1b60
#include "gen/pure3d.h"

#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/Render/Canvas.h"
class Device_2a1b60 {
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
    virtual void v14(int a, int b);
    virtual void v15(int a);
    virtual void v16(int a);
};

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
    virtual void v78(int a);
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87(int a);
    virtual void v88(int a);
};

class Sub_2a1b60;
class Sub_2a1b60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
    char pad[0x10 - 4];
    Sub_2a1b60* next;
    char pad2[0x44 - 0x14];
    int link;
};

class Obj_2a1b60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
    virtual void v8(int a);
    virtual char v9();
};

struct ObjHandle {
    Obj_2a1b60* obj;
    void FUN_002a4060();
};

struct Item_2a1b60 {
    char pad[8];
    int n;
    ObjHandle* handle;
    Sub_2a1b60* sub;
    int tag;
};

struct Helper_2a1b60 {
    void FUN_002a06d0(int link);
};

void pure3d::TranslucentTraversal::vfunc_4() {
    (*(*(Device_2a1b60***)&DAT_0052c2ac))->v15(0);
    for (unsigned int i = 0; i < (*(unsigned int *)&this->f_18); i++) {
        ObjHandle* handle = (*(Item_2a1b60 ** *)&this->f_28)[i]->handle;
        Sub_2a1b60* sub = (*(Item_2a1b60 ** *)&this->f_28)[i]->sub;
        (*(*(Device_2a1b60***)&DAT_0052c2ac))->v14(0, (*(Item_2a1b60 ** *)&this->f_28)[i]->n);
        if (handle->obj->v9() == 1 && (*(Helper_2a1b60 * *)&this->f_14) != 0 && sub->link != 0)
            (*(Helper_2a1b60 * *)&this->f_14)->FUN_002a06d0(sub->link);
        if ((*(Item_2a1b60 ** *)&this->f_28)[i]->tag == DAT_004e2314) {
            DAT_0052c2a8->v87(8);
            DAT_0052c2a8->v78(0);
        }
        Sub_2a1b60* inner = sub->next;
        if (inner != 0) {
            Obj_2a1b60* obj = handle->obj;
            obj->v8(inner->v3(obj->v7()));
            handle->FUN_002a4060();
            obj->v8(inner->v4(obj->v7()));
        } else {
            handle->FUN_002a4060();
        }
        if ((*(Item_2a1b60 ** *)&this->f_28)[i]->tag == DAT_004e2314)
            DAT_0052c2a8->v88(8);
    }
    (*(*(Device_2a1b60***)&DAT_0052c2ac))->v16(0);
}

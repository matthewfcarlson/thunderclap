#include "gen/global.h"
#include "gen/owners.h"

struct ObjA_18620 {
};
struct ObjB_18620 {
    void* Next();
};
struct ObjC_18620 {
    int Run();
};

bool CClearHitRecordsAction::vfunc_6(int x) {
    ObjA_18620* a = (*(ObjA_18620 * *)&this->f_1c);
    void* r = ((void *)((owners::Object_592a0 *)a)->FUN_000592a0());
    void* b = ((ObjB_18620*)r)->Next();
    if (b)
        ((ObjC_18620*)b)->Run();
    return false;
}

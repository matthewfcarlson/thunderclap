#include "gen/global.h"
#include "decls/data/game/global.h"
// data: gFlag_208820 = DAT_004c91da

class Subject_208820 {
  public:
    int GetState();
    void OnGlobal();
};
struct CWorldStreamManager_nv_208820 {
    void OnState();
    void OnOther(Subject_208820*);
    void Step1();
    void Step2();
    void Step3();
    void Step4();
    void Step5();
    void Step6();
};

void CWorldStreamManager::FUN_00208820() {
    if ((*(Subject_208820 * *)&this->f_aec)) {
        int r = (*(Subject_208820 * *)&this->f_aec)->GetState();
        this->f_af0 = 1;
        if (r == 3)
            ((CWorldStreamManager_nv_208820*)this)->OnState();
        else if (DAT_004c91da)
            (*(Subject_208820 * *)&this->f_aec)->OnGlobal();
        else
            ((CWorldStreamManager_nv_208820*)this)->OnOther((*(Subject_208820 * *)&this->f_aec));
    }
    ((CWorldStreamManager_nv_208820*)this)->Step1();
    ((CWorldStreamManager_nv_208820*)this)->Step2();
    ((CWorldStreamManager_nv_208820*)this)->Step3();
    ((CWorldStreamManager_nv_208820*)this)->Step4();
    ((CWorldStreamManager_nv_208820*)this)->Step5();
    ((CWorldStreamManager_nv_208820*)this)->Step6();
    this->f_04 = 0;
    this->f_24 = 0;
}

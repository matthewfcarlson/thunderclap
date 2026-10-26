// cl-flags: /O2 /GR /GX
#include "decls/data/game/global.h"
// data: g_GlobalFloatBits = DAT_004a0ff0

class Callback_e7c30 {
  public:
    virtual void Invoke(class Manager_e7c30* mgr, int result) = 0;
};

class Manager_e7c30 {
  public:
    bool IsActive();
    int GetValueBits();
    bool CheckFlag();
    void Action1();
    int Action2();
    bool CheckCondition();
    void Cleanup();
    void AltCleanup();
};


void __stdcall ProcessManager(Manager_e7c30* mgr, Callback_e7c30* cb) {
    bool flag = false;

    while (mgr->IsActive()) {
        int val = mgr->GetValueBits();
        if (val == (*(int*)&DAT_004a0ff0))
            flag = true;
    }

    if (!mgr->CheckFlag())
        return;

    mgr->Action1();

    while (mgr->CheckCondition()) {
        int result = mgr->Action2();
        if (flag) {
            if (cb) {
                cb->Invoke(mgr, result);
            } else {
                mgr->AltCleanup();
                break;
            }
        }
    }
    mgr->Cleanup();
}
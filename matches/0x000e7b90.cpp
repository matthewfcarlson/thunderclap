// cl-flags: /O2 /GR /GX

class Callback_e7b90 {
  public:
    virtual void Invoke(class Manager_e7b90* mgr, int result) = 0;
};

class Manager_e7b90 {
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

extern int g_GlobalFloatBits_004a0fec;

void __stdcall ProcessManager(Manager_e7b90* mgr, Callback_e7b90* cb) {
    bool flag = false;

    while (mgr->IsActive()) {
        int val = mgr->GetValueBits();
        if (val == g_GlobalFloatBits_004a0fec)
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
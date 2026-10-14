// cl-flags: /O2 /GR /GX

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

extern int g_GlobalFloatBits;

void __stdcall ProcessManager(Manager_e7c30* mgr, Callback_e7c30* cb) {
    bool flag = false;

    while (mgr->IsActive()) {
        int val = mgr->GetValueBits();
        if (val == g_GlobalFloatBits)
            flag = true;
    }

    if (!mgr->CheckFlag())
        goto final_cleanup;

    mgr->Action1();

    if (!mgr->CheckCondition())
        goto cleanup;

    do {
        int result = mgr->Action2();
        if (flag) {
            if (cb) {
                cb->Invoke(mgr, result);
            } else {
                mgr->AltCleanup();
                goto cleanup;
            }
        }
    } while (mgr->CheckCondition());

cleanup:
    mgr->Cleanup();
    return;

final_cleanup:
    return;
}
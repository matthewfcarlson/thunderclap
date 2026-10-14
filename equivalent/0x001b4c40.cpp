// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_001b4c40 @ 0x001b4c40
class Ref_1b4c40 {
public:
    virtual void AddRef();
    virtual void Release();
};

class RefHolder {
public:
    char pad00[0xc];
    Ref_1b4c40 *target;
    void FUN_001b4140(Ref_1b4c40 *r);
    void FUN_001b4060(Ref_1b4c40 *r);
    void FUN_001b4c40(Ref_1b4c40 *newTarget);
};

void RefHolder::FUN_001b4c40(Ref_1b4c40 *newTarget)
{
    Ref_1b4c40 *old = target;
    if (newTarget == old)
        return;
    Ref_1b4c40 *detached = 0;
    if (old) {
        old->AddRef();
        FUN_001b4140(old);
        detached = old;
        if (target) {
            target->Release();
            target = 0;
        }
    }
    if (newTarget) {
        FUN_001b4140(newTarget);
        if (newTarget)
            newTarget->AddRef();
    }
    if (target)
        target->Release();
    target = newTarget;
    if (newTarget)
        FUN_001b4060(newTarget);
    if (detached) {
        FUN_001b4060(detached);
        detached->Release();
    }
}

// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_001b4c40 @ 0x001b4c40
class Ref {
public:
    virtual void AddRef();
    virtual void Release();
};

class RefHolder {
public:
    char pad00[0xc];
    Ref *target;
    void FUN_001b4140(Ref *r);
    void FUN_001b4060(Ref *r);
    void FUN_001b4c40(Ref *newTarget);
};

void RefHolder::FUN_001b4c40(Ref *newTarget)
{
    Ref *old = target;
    if (newTarget == old)
        return;
    Ref *detached = 0;
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

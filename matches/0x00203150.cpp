class SubObj {
public:
    void Clear();
};

extern void *worldVtable;

class CWorldCollisionManager {
public:
    void *vptr;
    char pad4[0x0C];
    int mCount;
    char pad14[0x0C];
    SubObj mSub;
    CWorldCollisionManager *vfunc_0(unsigned char param);
};

void FreeMemA(void *p);
void FreeMemB(void *p);

CWorldCollisionManager *CWorldCollisionManager::vfunc_0(unsigned char param) {
    vptr = &worldVtable;
    mSub.Clear();
    if (mCount) {
        FreeMemA((void *)(mCount - 4));
    }
    if (param & 1) {
        FreeMemB(this);
    }
    return this;
}

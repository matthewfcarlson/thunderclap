// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_00106440 @ 0x00106440
struct Vec3_106440 { float x, y, z; };
struct Path_106440 {
    char pad0[0x14];
    int count;
    char loops;
    void FUN_00106170(int idx, Vec3_106440 pos);
    void FUN_001061a0(int from, int to, int a, int b, int c, int d, float e);
};
struct ThisWrap_00106440 {
    Path_106440* FUN_00106230(int id);
    bool FUN_00106440(int id, int idx, Vec3_106440 pos);
};

bool ThisWrap_00106440::FUN_00106440(int id, int idx, Vec3_106440 pos) {
    Path_106440* p = this->FUN_00106230(id);
    if (p == 0)
        return false;
    int n = p->count;
    if (idx < 0 || idx >= n)
        return false;
    p->FUN_00106170(idx, pos);
    int next;
    if (idx == n - 1)
        next = p->loops ? 0 : -1;
    else
        next = idx + 1;
    p->FUN_001061a0(idx, next, 0, 0, 0, 0, 0.5f);
    return true;
}

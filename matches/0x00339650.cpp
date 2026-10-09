extern "C" {
int FUN_00212d70(int L);
int FUN_00212f00(int L, int i);
void FUN_00212d80(int L, int i);
void FUN_00213640(int L, int a, int b);
int FUN_00213120(int L, int i);
void FUN_00213870(int L, int a, int b);
int FUN_003392c0(int L, int a);
void FUN_00339270(int L, int a, int b);
}

int FUN_00339650(int L, int idx) {
    if (idx <= 0 && idx > -10000) {
        idx = idx + FUN_00212d70(L) + 1;
    }
    if (!FUN_00212f00(L, -1)) {
        FUN_00212d80(L, -2);
        return -1;
    }
    FUN_00213640(L, idx, 1);
    int r = FUN_00213120(L, -1);
    FUN_00212d80(L, -2);
    if (r) {
        FUN_00213640(L, idx, r);
        FUN_00213870(L, idx, 1);
    } else {
        r = FUN_003392c0(L, idx);
        if (r < 2)
            r = 2;
        r++;
        FUN_00339270(L, idx, r);
    }
    FUN_00213870(L, idx, r);
    return r;
}

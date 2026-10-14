// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 46/46)
// FUN_000ae660 @ 0x000ae660
struct Snapshot {
    float f[17];
};

struct PadDevice {
    char pad00[0x18];
    char padbody[0x100];
    void FUN_000ada70(Snapshot* out);
    void FUN_000ada90(Snapshot* out);
    void FUN_000ad9f0();
};

struct Audio_ae660 {
    void FUN_00086180(int a, int b, int c, int d);
};

struct AudioHolder {
    char pad00[0x54];
    Audio_ae660* audio;
};

struct InputHub {
    void FUN_0023f6d0();
    void FUN_0023f6e0();
    void FUN_0023f6f0();
    void FUN_0023f700();
    char FUN_0023f710();
};

extern AudioHolder* DAT_004dd700;
extern InputHub* DAT_004dd6e8;

struct Controls {
    char pad00[4];
    PadDevice* device;
    char pad08[0x1b - 8];
    char g1b, g1c, g1d, g1e, g1f, g20, g21;
    void FUN_000ae660();
};

void Controls::FUN_000ae660()
{
    Snapshot a;
    Snapshot b;
    device->FUN_000ada70(&a);
    device->FUN_000ada90(&b);
    if (!(b.f[8] > 0.2f))
        return;
    if (g1b == 0) {
        if (a.f[3] > 0.2f) {
            DAT_004dd700->audio->FUN_00086180(0x2d, 0, 0, 0);
            g1b = 1;
        }
    } else if (a.f[3] < 0.2f) {
        g1b = 0;
    }
    if (g1c == 0) {
        if (a.f[0] > 0.2f) {
            DAT_004dd700->audio->FUN_00086180(0x3d, 0, 0, 0);
            g1c = 1;
        }
    } else if (a.f[0] < 0.2f) {
        g1c = 0;
    }
    if (g1f == 0) {
        if (b.f[10] > 0.2f) {
            DAT_004dd700->audio->FUN_00086180(0x5c, 0, 0, 0);
            g1f = 1;
        }
    } else if (b.f[10] < 0.2f) {
        g1f = 0;
    }
    if (g1d == 0) {
        if (a.f[2] > 0.2f) {
            DAT_004dd6e8->FUN_0023f6e0();
            g1d = 1;
        }
    } else if (a.f[2] < 0.2f) {
        g1d = 0;
    }
    if (g1e == 0) {
        if (a.f[1] > 0.2f) {
            DAT_004dd6e8->FUN_0023f6d0();
            g1e = 1;
        }
    } else if (a.f[1] < 0.2f) {
        g1e = 0;
    }
    if (g20 == 0) {
        if (a.f[7] > 0.2f) {
            DAT_004dd6e8->FUN_0023f700();
            g20 = 1;
        }
    } else if (a.f[7] < 0.2f) {
        g20 = 0;
    }
    if (g21 == 0) {
        if (a.f[8] > 0.2f) {
            DAT_004dd6e8->FUN_0023f6f0();
            g21 = 1;
        }
    } else if (a.f[8] < 0.2f) {
        g21 = 0;
    }
    if (DAT_004dd6e8->FUN_0023f710() != 0)
        device->FUN_000ad9f0();
}

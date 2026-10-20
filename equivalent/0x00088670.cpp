// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 34/34)
// FUN_00088670 @ 0x00088670
#include "gen/global.h"
struct Sim_88670;
struct Cfg_88670 { char pad[0x2c]; int v2c; };
struct Ctx_88670 {
    void *FUN_00086320();
    Cfg_88670 *FUN_00086380();
};
struct CSimControllerManager_nv_88670 {
    CSimControllerManager *FUN_000b3c90(int a);
    void FUN_000b3d00();
};
struct CCameraManager_nv_88670 {
    CCameraManager *FUN_0009dd20();
    void FUN_00098e20(Ctx_88670 *c);
};
struct Sys10 { void FUN_001b3fc0(); };
struct CSPManager_nv_88670 {
    CSPManager *FUN_001e7470();
    void FUN_001de360(Sim_88670 *s);
};
struct CPatrolPathManager_nv_88670 {
    CPatrolPathManager *FUN_00106e90(int n);
    void FUN_001063e0();
};
struct CPathManager_nv_88670 {
    CPathManager *FUN_001aec00();
    void FUN_001acd80();
};
struct F_88670 { F_88670 *FUN_00025a90(); void FUN_000243f0(Sim_88670 *s); };
struct CWorldCollisionManager_nv_88670 {
    CWorldCollisionManager *FUN_002023e0();
    void FUN_00203490();
};
struct CTriggerVolumeManager_nv_88670 {
    CTriggerVolumeManager *FUN_001ff580();
    void FUN_00200c10(Sim_88670 *s);
};
struct CScenarioManager_nv_88670 {
    CScenarioManager *FUN_001cd150();
    void FUN_001cfb20(Sim_88670 *s);
};
struct CEventManager_nv_88670 {
    CEventManager *FUN_001cc360();
    void FUN_001cb3f0(Sim_88670 *s);
};
struct K_88670 { K_88670 *FUN_001ebba0(Sim_88670 *s, Ctx_88670 *c); void FUN_001eebc0(); };
struct L_88670 { L_88670 *FUN_001f6c30(); void FUN_001f81c0(); };
struct CSimOverlayManager_nv_88670 {
    CSimOverlayManager *FUN_000d75c0();
    void FUN_000d6f00(int v);
};
struct CExtraRenderingCallback_nv_88670 {
    CExtraRenderingCallback *FUN_001bceb0();
};
struct O_88670 { O_88670 *FUN_00059ad0(); };
struct CGameDataHandler_nv_88670 {
    CGameDataHandler *FUN_001fae80();
    void FUN_001fb1e0();
};
struct CAmbientsManager_nv_88670 {
    CAmbientsManager *FUN_0007f950();
    void FUN_00078c50(Sim_88670 *s);
};
struct R_88670 { void FUN_00066c20(Sim_88670 *s); };

extern void *__cdecl FUN_0008d690(unsigned int n);
Sys10 *__cdecl FUN_001b6580();
void *__cdecl FUN_001b6990();
R_88670 *__stdcall FUN_000678d0();

struct Sim_88670 {
    void FUN_00088670(Ctx_88670 *ctx, int arg1);
    int pad0;
    CSimControllerManager *a;     // 4
    CCameraManager *b;     // 8
    CSPManager *c;     // c
    Sys10 *s10; // 10
    void *s14;
    CPatrolPathManager *d;     // 18
    CPathManager *e;     // 1c
    F_88670 *f;     // 20
    CWorldCollisionManager *g;     // 24
    CTriggerVolumeManager *h;     // 28
    CScenarioManager *i;     // 2c
    CEventManager *j;     // 30
    K_88670 *k;     // 34
    L_88670 *l;     // 38
    CSimOverlayManager *m;     // 3c
    CExtraRenderingCallback *n;     // 40
    O_88670 *o;     // 44
    CGameDataHandler *p;     // 48
    CAmbientsManager *q;     // 4c
    Cfg_88670 *cfg50; // 50
    Ctx_88670 *ctx;   // 54
    void *p58;  // 58
    char pad1[0x9d - 0x5c];
    char ready;
};

void Sim_88670::FUN_00088670(Ctx_88670 *arg0, int arg1)
{
    ctx = arg0;
    p58 = arg0->FUN_00086320();
    cfg50 = arg0->FUN_00086380();

    CSimControllerManager *ta = (CSimControllerManager *)FUN_0008d690(0xc);
    if (ta)
        ta = ((CSimControllerManager_nv_88670*)(ta))->FUN_000b3c90(arg1);
    a = ta;
    ((CSimControllerManager_nv_88670*)(ta))->FUN_000b3d00();

    CCameraManager *tb = (CCameraManager *)FUN_0008d690(0xc8);
    if (tb)
        tb = ((CCameraManager_nv_88670*)(tb))->FUN_0009dd20();
    b = tb;
    ((CCameraManager_nv_88670*)(tb))->FUN_00098e20(arg0);

    s10 = FUN_001b6580();
    s10->FUN_001b3fc0();

    CSPManager *tc = (CSPManager *)FUN_0008d690(0x1eee8);
    if (tc)
        tc = ((CSPManager_nv_88670*)(tc))->FUN_001e7470();
    c = tc;
    ((CSPManager_nv_88670*)(tc))->FUN_001de360(this);

    s14 = FUN_001b6990();

    CPatrolPathManager *td = (CPatrolPathManager *)FUN_0008d690(0x10);
    if (td)
        td = ((CPatrolPathManager_nv_88670*)(td))->FUN_00106e90(0x100);
    d = td;
    ((CPatrolPathManager_nv_88670*)(td))->FUN_001063e0();

    CPathManager *te = (CPathManager *)FUN_0008d690(0x2c);
    if (te)
        te = ((CPathManager_nv_88670*)(te))->FUN_001aec00();
    e = te;
    ((CPathManager_nv_88670*)(te))->FUN_001acd80();

    F_88670 *tf = (F_88670 *)FUN_0008d690(0xd40);
    if (tf)
        tf = tf->FUN_00025a90();
    f = tf;
    tf->FUN_000243f0(this);

    CWorldCollisionManager *tg = (CWorldCollisionManager *)FUN_0008d690(0x68);
    if (tg)
        tg = ((CWorldCollisionManager_nv_88670*)(tg))->FUN_002023e0();
    g = tg;
    ((CWorldCollisionManager_nv_88670*)(tg))->FUN_00203490();

    CTriggerVolumeManager *th = (CTriggerVolumeManager *)FUN_0008d690(0x43c);
    if (th)
        th = ((CTriggerVolumeManager_nv_88670*)(th))->FUN_001ff580();
    h = th;
    ((CTriggerVolumeManager_nv_88670*)(th))->FUN_00200c10(this);

    CScenarioManager *ti = (CScenarioManager *)FUN_0008d690(0x14ac);
    if (ti)
        ti = ((CScenarioManager_nv_88670*)(ti))->FUN_001cd150();
    i = ti;
    ((CScenarioManager_nv_88670*)(ti))->FUN_001cfb20(this);

    CEventManager *tj = (CEventManager *)FUN_0008d690(0x404);
    if (tj)
        tj = ((CEventManager_nv_88670*)(tj))->FUN_001cc360();
    j = tj;
    ((CEventManager_nv_88670*)(tj))->FUN_001cb3f0(this);

    K_88670 *tk = (K_88670 *)FUN_0008d690(8);
    if (tk)
        tk = tk->FUN_001ebba0(this, arg0);
    k = tk;
    tk->FUN_001eebc0();

    L_88670 *tl = (L_88670 *)FUN_0008d690(0x60);
    if (tl)
        tl = tl->FUN_001f6c30();
    l = tl;
    tl->FUN_001f81c0();

    CSimOverlayManager *tm = (CSimOverlayManager *)FUN_0008d690(0x10);
    if (tm)
        tm = ((CSimOverlayManager_nv_88670*)(tm))->FUN_000d75c0();
    m = tm;
    ((CSimOverlayManager_nv_88670*)(m))->FUN_000d6f00(ctx->FUN_00086380()->v2c);

    CExtraRenderingCallback *tn = (CExtraRenderingCallback *)FUN_0008d690(0x2c);
    if (tn)
        tn = ((CExtraRenderingCallback_nv_88670*)(tn))->FUN_001bceb0();
    n = tn;

    O_88670 *to = (O_88670 *)FUN_0008d690(0x10);
    if (to)
        to = to->FUN_00059ad0();
    o = to;

    CGameDataHandler *tp = (CGameDataHandler *)FUN_0008d690(0x34);
    if (tp)
        tp = ((CGameDataHandler_nv_88670*)(tp))->FUN_001fae80();
    p = tp;
    ((CGameDataHandler_nv_88670*)(tp))->FUN_001fb1e0();

    CAmbientsManager *tq = (CAmbientsManager *)FUN_0008d690(0x3838);
    if (tq)
        tq = ((CAmbientsManager_nv_88670*)(tq))->FUN_0007f950();
    q = tq;
    ((CAmbientsManager_nv_88670*)(tq))->FUN_00078c50(this);

    FUN_000678d0()->FUN_00066c20(this);
    ready = 1;
}

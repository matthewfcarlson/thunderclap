// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 75/76, incomplete)
// CHand2HandAgent::vfunc_22 @ 0x00101270
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);
struct V3_101270 { float x,y,z; float FUN_0022d110(); };
struct Name_101270 { void FUN_0027b040(const char *); };
struct Obj58_101270 { char pad[0x129]; char b129; };
struct World;
struct Arg1_101270 { char pad[0x1cbc]; int f1cbc; };
class P5c_101270 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual char v3(World *,Arg1_101270 *,V3_101270 *,float,int); char pad[12]; V3_101270 v10; };
struct Hub20_101270 { void FUN_00029250(int,V3_101270 *,int,int); };
struct World { char pad[0x20]; Hub20_101270 *p20; };
struct Rng_101270 { float FUN_00078780(); };
Rng_101270 *__cdecl FUN_000964d0();
float __cdecl FUN_0010ae50(World *,Arg1_101270 *,float,V3_101270 *,V3_101270 *,int,int);
struct Out_101270 { char pad[0x10c]; V3_101270 v10c; float f118; V3_101270 v11c,v128; char pad134[12]; Name_101270 name; char pad141[7]; char b148; };
class CHand2HandAgent { public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual char v11(Arg1_101270 *,float,float); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual char v18(float); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(Arg1_101270 *,Out_101270 *,float); virtual void v23();
 char pad04[0x54]; Obj58_101270 *p58; P5c_101270 *p5c; char pad60[4]; float f64; char pad68[8]; float f70; char pad74[4]; char b78,pad79,b7a,b7b; char pad7c[2]; char b7e,pad7f; float f80; char pad84[4]; V3_101270 v88,v94; int fa0; char pada4[12]; V3_101270 vb0,vbc; float fc8; char padcc[5]; char bd1,bd2,bd3; char padd4[8]; float fdc,fe0; char pade4[0x54]; V3_101270 v138,v144,v150,v15c,v168,v174; float f180; V3_101270 v184;
};
void CHand2HandAgent::v22(Arg1_101270 *actor, Out_101270 *out, float timeStep)
{
    bool approaching = fc8 < fdc || b7e != 0;
    volatile float quarterRange = (fe0 - fdc) * 0.25f;
    if ((double)(fe0 - fdc) * 0.25f + fdc < fc8) b7e = 0;
    else if (fc8 < fdc) b7e = 1;
    float limit = 1.0f;
    if (fc8 > fdc && fc8 < fe0 && !(*(char*)&DAT_004a1bfc)) limit = (fdc - fc8) / quarterRange;
    Rng_101270 *rng = FUN_000964d0();
    v15c.z = 0; v15c.y = 0; v15c.x = 0;
    v168.z = 0; v168.y = 0; v168.x = 0;
    out->v11c.x = vbc.x; out->v11c.y = vbc.y; out->v11c.z = vbc.z;
    out->v128.x = vbc.x; out->v128.y = vbc.y; out->v128.z = vbc.z;
    bool recoiling = false;
    volatile float facing = vbc.z * v94.z + vbc.y * v94.y + vbc.x * v94.x;
    if (approaching) {
        if (!bd2) {
            recoiling = true;
            v168.x = vbc.x * -1.0f; v168.y = vbc.y * -1.0f; v168.z = vbc.z * -1.0f;
            f64 = f64 - timeStep;
        }
        if (facing > 0.7f && rng->FUN_00078780() < 0.33f && !bd1 && b7b) {
            out->name.FUN_0027b040("evade_s"); out->b148 = 1; b7b = 0; return;
        }
    } else {
        v168.x = vbc.x; v168.y = vbc.y; v168.z = vbc.z;
    }
    if (f80 > 0.0f) { v168.z = 0; v168.y = 0; v168.x = 0; }
    if (!(*(char*)&DAT_004e0a99) && !bd1 && !bd3 && v18(1.5f)) {
        if (v11(actor, fc8, facing)) DAT_004dd700->p20->FUN_00029250(fa0, &v88, actor->f1cbc, 1);
    }
    if (!bd1 && !bd3 && f64 > 0.0f && b7a) v16();
    v138.z = 0; v138.y = 0; v138.x = 0;
    float threshold = p58->b129 ? 1.5f : 0.9900000095367432f;
    float result = FUN_0010ae50(DAT_004dd700, actor, 1.5f, &v150, &v138, 0, 0);
    if (result < 0.0f || result > threshold) {
        p58->b129 = 0; v138.z = 0; v138.y = 0; v138.x = 0;
    } else p58->b129 = 1;
    p5c->v10.x = v168.x; p5c->v10.y = v168.y; p5c->v10.z = v168.z;
    char hit = p5c->v3(DAT_004dd700, actor, &v15c, timeStep, 0);
    volatile float forceX = DAT_004a1c08 * v138.x;
    volatile float forceY = DAT_004a1c08 * v138.y;
    volatile float forceZ = DAT_004a1c08 * v138.z;
    double retention = 1.0f - DAT_004a1c08;
    volatile float oldX = retention * v174.x;
    volatile float oldY = retention * v174.y;
    volatile float oldZ = retention * v174.z;
    v174.z = oldZ + forceZ;
    v174.x = DAT_004a1c08 * v138.x + oldX;
    v174.y = oldY + forceY;
    volatile float *motion = &v168.x;
    motion[0] = v174.x + motion[0]; motion[1] = v174.y + motion[1]; motion[2] = v174.z + motion[2];
    motion[0] = motion[0] + v144.x; motion[1] = v144.y + motion[1]; motion[2] = v144.z + motion[2];
    double impactX = v15c.x + v15c.x;
    double impactY = v15c.y + v15c.y;
    volatile float impactZ = v15c.z + v15c.z;
    motion[0] = impactX + motion[0]; motion[1] = impactY + motion[1]; motion[2] = impactZ + motion[2];
    motion[0] = v150.x + motion[0]; motion[1] = v150.y + motion[1]; motion[2] = v150.z + motion[2];
    if (!hit && recoiling) {
        v168.z = 0; v168.y = 0; v168.x = 0; f64 = f64 - timeStep;
    } else recoiling = false;
    double magnitude = sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z);
    float strength = 1.0f < magnitude ? 1.0f : (float)magnitude;
    if (sqrt(v168.x * v168.x + v168.y * v168.y + v168.z * v168.z) < DAT_004a1c04) {
        v168.z = 0; v168.y = 0; v168.x = 0;
        out->v10c.z = 0; out->v10c.y = 0; out->v10c.x = 0; out->f118 = 0;
    } else {
        v168.FUN_0022d110(); out->f118 = strength;
        out->v10c.x = v168.x; out->v10c.y = v168.y; out->v10c.z = v168.z;
    }
    float zeroForce = DAT_004a1c0c * 0.0f;
    volatile float smoothX = zeroForce;
    volatile float smoothY = zeroForce;
    double damping = 1.0f - DAT_004a1c0c;
    volatile float dampX = damping * v184.x;
    volatile float dampY = damping * v184.y;
    volatile float dampZ = damping * v184.z;
    v184.z = dampZ + zeroForce; v184.x = dampX + smoothX; v184.y = dampY + smoothY;
    if (b78 && bd3 && fc8 < fdc) {
        if (recoiling && !hit) {
            if (vb0.z * v94.z + vb0.y * v94.y + vb0.x * v94.x < -0.98f && f70 > 0.75f) {
                out->name.FUN_0027b040("awestruck"); out->b148 = 1;
            }
            out->f118 = 0; out->v11c.x = vbc.x; out->v11c.y = vbc.y; out->v11c.z = vbc.z; b78 = 0;
        } else {
            out->f118 = 1.0f; out->v11c.x = -vbc.x; out->v11c.y = -vbc.y; out->v11c.z = -vbc.z;
        }
    } else {
        out->v11c.x = vbc.x; out->v11c.y = vbc.y; out->v11c.z = vbc.z;
    }
    out->v10c.x = v168.x; out->v10c.y = v168.y; out->v10c.z = v168.z;
    out->f118 = limit < out->f118 ? limit : out->f118;
}
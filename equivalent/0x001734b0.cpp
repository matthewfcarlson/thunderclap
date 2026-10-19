// STATUS: equivalent (tools/equiv.py level 3: 3104 inputs, branch coverage 65/68, incomplete)
// hulkfight::motion::JointTrackerAction::vfunc_5 @ 0x001734b0
#include "decls/data/game/hulkfight/motion.h"
extern "C" int __cdecl _isnan(double); extern "C" double fabs(double);
struct V3_1734b0 { float x,y,z; float FUN_0022d110(); void FUN_000111b0(const V3_1734b0 *,const V3_1734b0 *); };
struct Mat_1734b0 { float m[16]; void FUN_0022b980(); void FUN_0022baf0(const V3_1734b0 *,float); void FUN_0022c3b0(const V3_1734b0 *,V3_1734b0 *); void FUN_0022ca90(Mat_1734b0 *,Mat_1734b0 *); void FUN_0022bec0(const V3_1734b0 *,const V3_1734b0 *); void FUN_0022c0b0(); };
struct A24; struct Part8 { void FUN_000350c0(V3_1734b0 *); void FUN_00035020(V3_1734b0 *); }; struct Obj2c { void FUN_0022c2b0(float *,V3_1734b0 *); };
struct Obj11c_1734b0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual char *v8(); };
struct Body5 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Obj2c *v15(); char pad04[0x11c-4]; Obj11c_1734b0 *f11c; char pad120[0x148-0x120]; Part8 *f148; };
struct Obj74 { virtual void v0(); virtual void v1(); char pad04[4]; void *f8; int fc; char pad10[0x40-0x10]; float f40,f44,f48; };
struct R8 { char pad0[0x28]; unsigned short *f28; }; struct Q64 { char pad0[8]; R8 *f8; char pad0c[0x1c-0xc]; Mat_1734b0 *f1c; };
struct YObj_1734b0 { Obj74 *FUN_0003ffe0(float,float,int,Obj74 *,V3_1734b0 *); float FUN_000354c0(); };
struct ZObj { char pad0[0x64]; Q64 *f64; void FUN_00222970(A24 *,int); void FUN_00222890(A24 *,float,float,float,float,float,float); };
struct XObj_1734b0 { YObj_1734b0 *FUN_00059a30(); ZObj *FUN_00059a40(); }; struct F20_1734b0 { XObj_1734b0 *FUN_000592a0(); };
struct Sub18_1734b0 { void FUN_00221c60(Mat_1734b0 *); }; struct A24 { char pad0[0x10]; int f10; char pad14[4]; Sub18_1734b0 sub18; };
struct P1c_1734b0 { char pad0[0x38]; float f38,f3c,f40,f44,f48; char b4c; char pad4d[3]; float f50,f54; int f58; float f5c,f60,f64; };
float __cdecl FUN_00018a20(float); float __cdecl FUN_000189c0(float); float __cdecl FUN_00224ea0(float,float); float __cdecl FUN_00224fc0(float,float); void __cdecl FUN_00224d70(float,V3_1734b0 *);
struct TrackerWork {
    float temporary, step; V3_1734b0 aim; union {char byte; int bits; float scalar;} setting;
    V3_1734b0 target; ZObj *controller; V3_1734b0 direction, rotationAxis; float axisPadding;
    V3_1734b0 jointPosition, forward; int jointIndex; YObj_1734b0 *tracker; Q64 *skeleton;
    Mat_1734b0 rotation, parent, joint, orientation, combined, result;
};
class JointTrackerAction { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual bool v5(int,float); char pad04[0x1c-4]; P1c_1734b0 *p1c; F20_1734b0 *p20; A24 *p24; V3_1734b0 v28; Mat_1734b0 m34; Obj74 *f74; };
bool JointTrackerAction::v5(int phase,float dt) {
    TrackerWork w;
    if (phase) return true;
    XObj_1734b0 *actor=p20->FUN_000592a0();
    YObj_1734b0 *tracker=actor->FUN_00059a30(); w.tracker=tracker;
    ZObj *controller=actor->FUN_00059a40(); Q64 *skeleton=controller->f64;
    w.controller=controller;
    w.temporary=p1c->f50; w.step=p1c->f54; w.setting.byte=p1c->b4c; w.skeleton=skeleton;
    Obj74 *object=tracker->FUN_0003ffe0(w.temporary,w.step,w.setting.bits,f74,&w.direction);
    if (object) object->v0();
    if (f74) f74->v1();
    f74=object;
    w.jointIndex=p24->f10;
    w.joint=skeleton->f1c[w.jointIndex];
    w.jointPosition.x=w.joint.m[12]; w.jointPosition.y=w.joint.m[13]; w.jointPosition.z=w.joint.m[14];
    w.target.x=0.0f; w.target.y=0.0f; w.target.z=0.0f;
    if (!object) {
        if (p1c->b4c) { controller->FUN_00222970(p24,0); return true; }
        w.temporary=w.direction.FUN_0022d110(); w.temporary=(float)fabs(w.temporary);
        if (w.temporary<=1e-5f) { controller->FUN_00222970(p24,0); return true; }
    } else {
        w.target.x=object->f40; w.target.y=object->f44; w.target.z=object->f48;
        int kind=object->fc,mode=p1c->f58;
        if (kind==1) {
            Part8 *part=(Part8 *)object->f8;
            if (mode==1) part->FUN_000350c0(&w.target);
            else if (mode==2) part->FUN_00035020(&w.target);
        } else if (kind==5) {
            Body5 *body=(Body5 *)object->f8;
            if (body) {
                Part8 *part=body->f148;
                if (part) {
                    if (mode==1) part->FUN_000350c0(&w.target);
                    else if (mode==2) part->FUN_00035020(&w.target);
                } else if (mode==1 || mode==2) {
                    Obj11c_1734b0 *source=body->f11c;
                    if (source) {
                        char *data=source->v8();
                        if (data) {
                            w.rotationAxis.x=*(float *)(data+0x2c); w.rotationAxis.y=*(float *)(data+0x30);
                            w.rotationAxis.z=*(float *)(data+0x34); w.axisPadding=*(float *)(data+0x38);
                            body->v15()->FUN_0022c2b0((float *)&w.rotationAxis,&w.target);
                        }
                    }
                }
            }
        }
        if (_isnan(w.target.x) || _isnan(w.target.y) || _isnan(w.target.z)
            || fabs(w.target.x)>=5000.0f || fabs(w.target.y)>=5000.0f || fabs(w.target.z)>=5000.0f) {
            if (f74) { f74->v1(); f74=0; }
            if (p1c->b4c) { controller->FUN_00222970(p24,0); return true; }
            w.temporary=w.direction.FUN_0022d110(); w.temporary=(float)fabs(w.temporary);
            if (w.temporary<=1e-5f) { controller->FUN_00222970(p24,0); return true; }
        } else {
            w.direction.x=w.target.x-w.jointPosition.x;
            w.direction.y=w.target.y-w.jointPosition.y;
            w.direction.z=w.target.z-w.jointPosition.z;
            w.direction.FUN_0022d110();
        }
    }
    w.joint.FUN_0022c3b0(&v28,&w.forward);
    w.step=p1c->f38;
    if (w.step<=0.0f) w.aim=w.direction;
    else {
        double dot=w.forward.z*w.direction.z+w.forward.y*w.direction.y+w.forward.x*w.direction.x;
        w.temporary=(float)dot;
        float angle;
        if (dot>=1.0f) angle=0.0f;
        else if (w.temporary<=-1.0f) angle=3.1415927410125732f;
        else angle=FUN_00018a20(w.temporary);
        w.step=w.step*dt;
        if (angle<=w.step) w.aim=w.direction;
        else {
            w.rotationAxis.FUN_000111b0(&w.direction,&w.forward);
            w.rotation.FUN_0022baf0(&w.rotationAxis,w.step);
            w.rotation.FUN_0022c3b0(&w.forward,&w.aim);
        }
    }
    float pitch=FUN_000189c0(w.aim.y); w.temporary=pitch;
    w.step=p1c->f3c; w.setting.scalar=p1c->f40;
    if (pitch<w.step) {
        w.rotation.FUN_0022b980();
        w.jointPosition.z=-w.aim.x; w.jointPosition.x=w.aim.z; w.jointPosition.y=0.0f;
        w.rotation.FUN_0022baf0(&w.jointPosition,w.step-w.temporary);
        w.rotationAxis=w.aim;
        w.rotation.FUN_0022c3b0(&w.rotationAxis,&w.aim);
    } else if (w.temporary>w.setting.scalar) {
        w.rotation.FUN_0022b980();
        w.rotationAxis.z=-w.aim.x; w.rotationAxis.x=w.aim.z; w.rotationAxis.y=0.0f;
        w.rotation.FUN_0022baf0(&w.rotationAxis,w.setting.scalar-w.temporary);
        w.jointPosition=w.aim;
        w.rotation.FUN_0022c3b0(&w.jointPosition,&w.aim);
    }
    w.setting.scalar=FUN_00224ea0(w.aim.x,w.aim.z);
    w.temporary=tracker->FUN_000354c0();
    float delta=FUN_00224fc0(w.temporary,w.setting.scalar);
    w.setting.scalar=p1c->f44; w.step=p1c->f48;
    bool adjust=false; double limit=0.0;
    if (delta<w.setting.scalar) { limit=w.setting.scalar; adjust=true; }
    else if (delta>w.step) { limit=w.step; adjust=true; }
    if (adjust) {
        w.aim.z=*(float *)&DAT_004b7d20; w.aim.x=*(float *)&DAT_004b7d18;
        FUN_00224d70((float)(limit+w.temporary),&w.aim);
        w.aim.FUN_0022d110();
    }
    w.orientation.FUN_0022b980();
    w.rotationAxis.x=0.0f; w.rotationAxis.y=1.0f; w.rotationAxis.z=0.0f;
    w.orientation.FUN_0022bec0(&w.aim,&w.rotationAxis);
    w.combined.FUN_0022ca90(&m34,&w.orientation);
    w.parent=w.skeleton->f1c[w.skeleton->f8->f28[w.jointIndex]];
    w.parent.m[14]=0.0f; w.parent.m[13]=0.0f; w.parent.m[12]=0.0f;
    w.parent.FUN_0022c0b0();
    w.result.FUN_0022ca90(&w.combined,&w.parent);
    p24->sub18.FUN_00221c60(&w.result);
    w.controller->FUN_00222890(p24,-1.0f,p1c->f5c,1.0f,p1c->f60,p1c->f64,-1.0f);
    return true;
}
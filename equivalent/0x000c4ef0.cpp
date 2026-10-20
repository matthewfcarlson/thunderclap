// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_000c4ef0 @ 0x000c4ef0
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" void *__cdecl FUN_0008d690(unsigned int size);
extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }


struct Vec3_c4ef0 {
    float x, y, z;
};

struct Timer {
    float scale;
    int last;
    Timer *FUN_00095f50();
    float FUN_00095f70();
};

class VectorCamera_c4ef0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setNear(float f);
    virtual void v8();
    virtual void setFar(float f);

    VectorCamera_c4ef0 *FUN_002939a0();
    void FUN_00293af0(Vec3_c4ef0 *v);
    void FUN_00293a90(Vec3_c4ef0 *v);
};

class Renderer_c4ef0 {
  public:
    virtual void v0();
    char pad[0x20 - 4];
    unsigned color;
    char pad2[4];
    int field_28;
    int field_2c;

    Renderer_c4ef0 *FUN_00294880();
    void FUN_00293e90(unsigned color);
    void FUN_00294980(VectorCamera_c4ef0 *cam);
};

class FEControllerSystem {
  public:
    virtual ~FEControllerSystem();
    int field_04;

    FEControllerSystem *FUN_000b3de0();
    void FUN_000b3e00(void *a);
};

class CFESoundManager {
  public:
    virtual void v0();
    int field_04;
    CFESoundManager() : field_04(0) {}
};

struct Obj68_c4ef0 {
    virtual void v0();
    Obj68_c4ef0 *FUN_0028edb0();
};

struct Obj64_c4ef0 {
    Obj64_c4ef0 *FUN_000c43a0(void *owner);
};

struct Singleton_c4ef0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void setLanguage(void *lang);
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void registerCallback(void (*fn)(), void *owner);
    char pad[0x2220 - 4];
    char flag;
};

struct Input_c4ef0 {
    char pad[0xd88];
    void *owner;
    void FUN_00092bd0(void *owner);
};

struct Frontend_c4ef0 {
    char pad0[0x20];
    Renderer_c4ef0 *renderer;
    VectorCamera_c4ef0 *camera;
    char pad1[0x34 - 0x28];
    void *field_34;
    char pad2[0x40 - 0x38];
    CFESoundManager *sound;
    void *field_44;
    void *field_48;
    Input_c4ef0 *input;
    void *field_50;
    char pad3[0x58 - 0x54];
    void *field_58;
    void *field_5c;
    FEControllerSystem *controllers;
    Obj64_c4ef0 *field_64;
    Obj68_c4ef0 *field_68;
    char pad4[0x1880 - 0x6c];
    int field_1880;
    char text1[0x80];
    char text2[0x80];
    char text3[0x80];
    char pad5[4];
    int field_1a08;

    void FUN_000c1790(char *lang);
    void FUN_000c4ef0(void *a1, void *a2, void *a3, Input_c4ef0 *a4, void *a5, void *a6, void *a7);
};

Singleton_c4ef0 *FUN_000fc3d0();
void FUN_000fc060(const char *file, FEControllerSystem *ctl, CFESoundManager *snd, Renderer_c4ef0 *r);
void FUN_00294c70(void *src, void *dst, int n);
void FUN_000d3d80();

void Frontend_c4ef0::FUN_000c4ef0(void *a1, void *a2, void *a3, Input_c4ef0 *a4, void *a5, void *a6, void *a7)
{
    void *p = FUN_0008d690(0x140);
    renderer = p ? ((Renderer_c4ef0 *)p)->FUN_00294880() : 0;
    renderer->v0();
    renderer->field_28 = 0;
    renderer->field_2c = 6;
    renderer->color = 0xff000000;
    renderer->FUN_00293e90(0xff505050);

    p = FUN_00263ea0(0xf8);
    camera = p ? ((VectorCamera_c4ef0 *)p)->FUN_002939a0() : 0;
    camera->v0();
    camera->setNear(0.1f);
    camera->setFar(100.0f);
    Vec3_c4ef0 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = -13.0f;
    camera->FUN_00293af0(&v);
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    camera->FUN_00293a90(&v);
    renderer->FUN_00294980(camera);

    if (controllers != 0) {
        delete controllers;
        controllers = 0;
    }
    p = FUN_0008d690(8);
    FEControllerSystem *ctl = p ? ((FEControllerSystem *)p)->FUN_000b3de0() : 0;
    controllers = ctl;
    ctl->FUN_000b3e00(a1);
    field_58 = a1;

    p = FUN_0008d690(8);
    CFESoundManager *snd = 0;
    if (p)
        snd = new (p) CFESoundManager();
    field_5c = a6;
    sound = snd;

    Timer timer;
    timer.FUN_00095f50();
    timer.FUN_00095f70();

    FUN_000fc060("frontend/lang/str_en.txt", controllers, sound, renderer);
    FUN_000fc3d0()->setLanguage(field_5c);
    char flag = DAT_004dd839;
    FUN_000fc3d0()->flag = flag;
    FUN_000c1790(DAT_004dd8d4);
    timer.FUN_00095f70();
    FUN_000fc3d0()->registerCallback(FUN_000d3d80, this);

    p = FUN_0008d690(8);
    field_64 = p ? ((Obj64_c4ef0 *)p)->FUN_000c43a0(this) : 0;

    p = FUN_00263ea0(0x20);
    field_68 = p ? ((Obj68_c4ef0 *)p)->FUN_0028edb0() : 0;
    field_68->v0();

    field_48 = a3;
    field_44 = a2;
    input = a4;
    a4->FUN_00092bd0(this);
    field_50 = a5;
    field_1880 = 0;
    FUN_00294c70(((char*)&DAT_00409f04), text1, 0x40);
    FUN_00294c70(((char*)&DAT_00409f00), text2, 0x40);
    FUN_00294c70(((char*)&DAT_00409efc), text3, 0x40);
    field_34 = a7;
    field_1a08 = 0;
}

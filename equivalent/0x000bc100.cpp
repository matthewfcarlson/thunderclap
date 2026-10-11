// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_000bc100 @ 0x000bc100
extern "C" void __cdecl FUN_000fc130(const void *arg);
extern "C" void __cdecl FUN_0008d340(void *p);
extern "C" void __cdecl FUN_000fc160();

class Scene {
public:
    void FUN_000f7ce0();
};

class Resource {
public:
    void FUN_001bf860(int flag);
    void FUN_001bdf00();
};

class Hook {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
};

class Pool {
public:
    void FUN_002665a0();
};

class Display {
public:
    void FUN_00294980(int arg);
};

struct Flag {
    char pad0[4];
    char ready;
};

extern "C" Scene *__cdecl FUN_000fc1b0();
extern "C" Hook *__cdecl FUN_000fc3d0();
extern "C" Flag *__cdecl FUN_0008e090();
extern "C" const void *DAT_0049f3ac;
extern Pool *DAT_004dd9cc;

class Loader {
public:
    void FUN_000bc100();

    char pad0[0x10];
    int state;
    char pad1[0x20 - 0x14];
    Display *display;
    int displayArg;
    char active;
    char pad2[0x5c - 0x29];
    Resource *resource;
    char pad3[0x6c - 0x60];
    void *slotsA[128];
    void *slotsB[128];
};

void Loader::FUN_000bc100()
{
    active = 0;
    FUN_000fc130(DAT_0049f3ac);
    for (int i = 0; i < 128; i++) {
        if (slotsA[i] == 0)
            break;
        FUN_0008d340(slotsA[i]);
        slotsA[i] = 0;
    }
    for (int i = 0; i < 128; i++) {
        if (slotsB[i] == 0)
            break;
        FUN_0008d340(slotsB[i]);
        slotsB[i] = 0;
    }
    FUN_000fc160();
    Scene *scene = FUN_000fc1b0();
    if (scene)
        scene->FUN_000f7ce0();
    if (resource) {
        resource->FUN_001bf860(1);
        resource->FUN_001bdf00();
    }
    Hook *hook = FUN_000fc3d0();
    if (hook)
        hook->vf65();
    DAT_004dd9cc->FUN_002665a0();
    display->FUN_00294980(displayArg);
    state = 6;
    FUN_0008e090()->ready = 1;
}

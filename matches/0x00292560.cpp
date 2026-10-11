struct Context {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setWindow(void*);
};
struct Version {
    int major, minor, build;
    int unused;
    char description[256];
};
struct Device {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void version(Version*);
    virtual void v5();
    virtual void v6();
    virtual Context* create(int);
    virtual void* info(Context*);
};
struct Object {
    char pad[0xe0];
    void* a;
    void* b;
    void* c;
    Object* FUN_0028f800(Device*, Context*, void*);
    void FUN_0028f980();
    void* FUN_0028fa30(int);
};
extern void __cdecl FUN_0028fcc0(const char*, ...);
extern void __cdecl FUN_0031ba60(int, int, Device**);
extern void __cdecl FUN_002c3230(Device*);
extern void* __cdecl FUN_0008d690(unsigned);
extern void __cdecl FUN_002c31b0();
extern Object* DAT_0052c2b4;
extern void* DAT_0052c2ac;
extern void* DAT_0052c2a8;
extern void* DAT_0052c2a0;
extern void* DAT_0052c2a4;
struct Owner {
    Object* object;
    Object* FUN_00292560(void*);
};
Object* Owner::FUN_00292560(void* window) {
    Device* device;
    Version version;
    FUN_0028fcc0("Pure3D v%s, released %s\n", "3.19.Hairclub", "2-November-2004");
    FUN_0031ba60(18, 11, &device);
    FUN_002c3230(device);
    Context* context = device->create(0);
    context->setWindow(window);
    void* info = device->info(context);
    device->version(&version);
    FUN_0028fcc0("Context created: PDDI v%d.%d (build %d), '%s'\n", version.major, version.minor,
                 version.build, version.description);
    Object* allocated = (Object*)FUN_0008d690(0xf8);
    object = allocated ? allocated->FUN_0028f800(device, context, info) : 0;
    object->FUN_0028f980();
    Object* current = object;
    DAT_0052c2b4 = current;
    DAT_0052c2ac = current->FUN_0028fa30(0);
    DAT_0052c2a8 = current->b;
    DAT_0052c2a0 = current->a;
    DAT_0052c2a4 = current->c;
    FUN_002c31b0();
    return object;
}
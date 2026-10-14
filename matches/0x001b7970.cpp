struct Renderer_1b7970 {
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
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void set54(int);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void set58(int);
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void reset91();
};
struct Resource_1b7970 {
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void stop();
};
struct Container_1b7970 {
    void FUN_00086400();
};
struct Control_1b7970 {
    void FUN_0008db60(int);
};
struct Manager_1b7970 {
    void FUN_001bf860(int);
};
struct Simulation {
    void FUN_001eb890();
    void FUN_001eb2a0(float, int);
};
struct Provider_1b7970 {
    Simulation* FUN_000862e0();
};
struct Globals_1b7970 {
    char pad[0x50];
    Manager_1b7970* manager;
    Provider_1b7970* provider;
};
extern Globals_1b7970* DAT_004dd700;
extern Renderer_1b7970* DAT_0052c2a8;
extern unsigned char DAT_004e222c, DAT_004e222d;
void __cdecl thunk_FUN_00267090(void*);
struct Owner_1b7970 {
    char pad0[12];
    Resource_1b7970* resource;
    char pad10[0x108];
    Container_1b7970* container;
    Control_1b7970* control;
    int unknown120;
    void* allocation;
    int state;
    char pad12c[5];
    unsigned char active;
    void FUN_001b7970();
};
void Owner_1b7970::FUN_001b7970() {
    if (!resource)
        return;
    DAT_0052c2a8->reset91();
    DAT_0052c2a8->set54(1);
    DAT_0052c2a8->set58(1);
    DAT_004e222c = 1;
    DAT_004e222d = 1;
    if (resource)
        resource->stop();
    if (resource) {
        Resource_1b7970* old = resource;
        resource = 0;
        old->release();
    }
    Container_1b7970* c = container;
    state = 0;
    c->FUN_00086400();
    if (allocation) {
        thunk_FUN_00267090(allocation);
        allocation = 0;
    }
    allocation = 0;
    DAT_004dd700->manager->FUN_001bf860(1);
    DAT_004dd700->provider->FUN_000862e0()->FUN_001eb890();
    for (int i = 0; i < 10; ++i)
        DAT_004dd700->provider->FUN_000862e0()->FUN_001eb2a0(0.01f, 0);
    Control_1b7970* ctl = control;
    active = 0;
    ctl->FUN_0008db60(0);
}

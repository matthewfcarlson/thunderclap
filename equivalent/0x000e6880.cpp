// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 14/14)
// FEThingsBase::vfunc_29 @ 0x000e6880
// FEThingsBase::vfunc_29 @ 0x000e6880: selects the thing whose name matches, then refreshes the screen
extern "C" int __cdecl strcmp(const char *, const char *);

class Thing {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *GetName();
};

class FEThingsBase {
public:
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
    virtual void vfunc_29(const char *name);
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
    virtual void Refresh(int mode);
    char pad04[0x20c - 4];
    Thing *things[256];
    char pad60c[0x1830 - 0x60c];
    int f1830;
    float f1834;
    int f1838;
    Thing *selected;
};

void FEThingsBase::vfunc_29(const char *name)
{
    selected = 0;
    for (int i = 0; i < 256; i++) {
        if (things[i] == 0)
            continue;
        if (strcmp(name, things[i]->GetName()) == 0) {
            selected = things[i];
            break;
        }
    }
    Refresh(4);
    f1830 = 2;
    f1838 = 0;
    f1834 = 1.0f;
}

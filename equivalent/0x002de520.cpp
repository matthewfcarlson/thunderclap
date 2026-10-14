// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ImageConverter::vfunc_5 @ 0x002de520
extern "C" void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern char DAT_004d098c[];
extern char DAT_004d09a8[];

class Target {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void SetOption(int option, int value);      // slot 11 (0x2c)
    virtual void v12();
    virtual int GetProperty(int key, int flags);        // slot 13 (0x34)
    virtual void Select(int key);                       // slot 14 (0x38)
};

class Converted {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int GetValue();                             // slot 18 (0x48)
};

class Source {
public:
    char pad0[0x10];
    Target* target;     // 0x10
};

class ImageConverter {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void vfunc_5(void* dest, Source* src, int key);
    virtual void v6();
    virtual void Apply(void* dest, int value);         // slot 7 (0x1c)
};

void ImageConverter::vfunc_5(void* dest, Source* src, int key)
{
    if (src == 0)
        return;
    Apply(dest, src->target->GetProperty(key, 0));
    src->target->Select(key);
    Converted* c = (Converted*)FUN_00344e74(dest, 0, DAT_004d098c, DAT_004d09a8, 0);
    if (c != 0) {
        int value = c->GetValue();
        src->target->SetOption(0x100, value);
    }
}

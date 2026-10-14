// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000f2b10 @ 0x000f2b10
inline void *operator new(unsigned int, void *p) throw() { return p; }
namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}
namespace pure3d { class CompositeDrawable; }

extern "C" int sprintf(char *, const char *, ...);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

class Ref_f2b10 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f2b10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2b10 *v3(content::LoadInventory::DynamicCasterBase *caster, unsigned int lo, unsigned int hi);
};
extern Loader_f2b10 *DAT_004dd9cc;
unsigned __int64 __cdecl FUN_0027b020(const char *name);

class Owner_f2b10 {
public:
    char pad000[0x1bc];
    Ref_f2b10 *drawables[10];
    void LoadDrawables(const char *prefix);
};

void Owner_f2b10::LoadDrawables(const char *prefix)
{
    unsigned int cookie = DAT_004d9968;
    char name[0x20];
    for (int i = 1; i <= 10; i++) {
        sprintf(name, "%s_%d", prefix, i);
        Loader_f2b10 *ld = DAT_004dd9cc;
        unsigned __int64 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
        Ref_f2b10 *r = ld->v3(&caster, (unsigned int)id, (unsigned int)(id >> 32));
        drawables[i - 1] = r;
        if (r != 0)
            r->AddRef();
    }
    __security_check_cookie(cookie);
}

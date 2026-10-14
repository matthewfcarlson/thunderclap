// STATUS: equivalent (tools/equiv.py level 3: 2981 inputs, branch coverage 8/8)
// FUN_001ea5a0 @ 0x001ea5a0
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace audio { class Clip; }

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

struct ClipRef_1ea5a0 {
    unsigned int idLo;
    unsigned int idHi;
};

struct Clip {
    char pad0[0x22];
    unsigned short refs;
};

class ClipLookup_1ea5a0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Clip *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned int lo, unsigned int hi);
    virtual void store(unsigned int lo, unsigned int hi, Clip *clip);
};

struct Request {
    char pad0[4];
    ClipRef_1ea5a0 *ref;
};

extern char DAT_004e36bc;
bool __cdecl FUN_00245720(Clip **out, void *source, const char *name, void *option);
void FUN_001e8a60();

struct Arg_1ea5a0 {
    union {
        Request *request;
        Clip *clip;
    };
};

class ClipUser {
public:
    char pad0[0x518];
    ClipLookup_1ea5a0 *clips;
    void Acquire(Arg_1ea5a0 arg);
};

void ClipUser::Acquire(Arg_1ea5a0 arg)
{
    Request *req = arg.request;
    ClipRef_1ea5a0 *ref = req->ref;
    content::LoadInventory::DynamicCaster<audio::Clip> caster;
    arg.clip = clips->lookup(&caster, ref->idLo, ref->idHi);
    if (arg.clip == 0) {
        if (FUN_00245720(&arg.clip, &DAT_004e36bc, (const char *)req->ref, (void *)&FUN_001e8a60)) {
            if (arg.clip != 0)
                clips->store(req->ref->idLo, req->ref->idHi, arg.clip);
        }
    }
    if (arg.clip != 0)
        arg.clip->refs++;
}

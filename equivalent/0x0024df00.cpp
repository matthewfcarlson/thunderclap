// STATUS: equivalent (tools/equiv.py level 3: 690 inputs, branch coverage 24/24)
// FUN_0024df00 @ 0x0024df00
#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
namespace om {
class __declspec(novtable) TypeBase {
public:
    virtual void v0();
    virtual void v1();
    char pad04[0x3c];
    void FUN_002580e0();
    void FUN_002584d0(const void* a, const void* b, int size, int align);
    TypeBase(const void* a, const void* b, int size, int align) { FUN_002584d0(a, b, size, align); }
};
template <class T> class TypeT : public TypeBase {
public:
    TypeT(const void* a, const void* b, int size, int align) : TypeBase(a, b, size, align) {}
    virtual void v0();
    virtual void v1();
};
class __declspec(novtable) AttribBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad04[0x18];
    void FUN_0025fba0(const void* reg, const char* name, int offset);
    AttribBase(const void* reg, const char* name, int offset) { FUN_0025fba0(reg, name, offset); }
};
template <class T> class MetaTypeAttribScalar : public AttribBase {
public:
    MetaTypeAttribScalar(const void* reg, const char* name, int offset, T mn, T def, T cur, const char* label, const float* limit)
        : AttribBase(reg, name, offset) { lo = mn; value = def; hi = cur; this->label = label; this->limit = limit; }
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    T lo;
    T value;
    T hi;
    const char* label;
    const float* limit;
};
}
struct Registry_24df00 { virtual void v0(); };
extern void* __cdecl FUN_00247530(om::TypeBase* temp);
void FUN_0024df00()
{
        {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.room", 0x28, -10000, 0, -10000, "Room", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.roomHF", 0x2c, -10000, 0, -10000, "Room High Frequency", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.roomRolloffFactor", 0x30, 0.0f, 10.0f, 0.0f, "Room Roll Off Factor", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.decayTime", 0x34, 0.1f, 20.0f, 0.1f, "Decay Time", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.decayHFRatio", 0x38, 0.1f, 2.0f, 0.1f, "Decay HF Ratio", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.reflections", 0x3c, -10000, 1000, -10000, "Reflections", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.reflectionsDelay", 0x40, 0.0f, 0.3f, 0.0f, "Reflections Delay", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<int> > temp(((unsigned int*)&DAT_004e6328), ((unsigned int*)&DAT_004e6320), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<int>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.reverb", 0x44, -10000, 2000, -10000, "Reverb", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.reverbDelay", 0x48, 0.0f, 0.1f, 0.0f, "Reverb Delay", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.diffusion", 0x4c, 0.0f, 100.0f, 0.0f, "Diffusion", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.density", 0x50, 0.0f, 100.0f, 0.0f, "Density", &DAT_003f335c);
    }
    {
        om::TypeT<om::MetaTypeAttribScalar<float> > temp(((unsigned int*)&DAT_004e6338), ((unsigned int*)&DAT_004e6330), 0x30, 4);
        void* p = FUN_00247530(&temp);
        temp.FUN_002580e0();
        if (p)
            new (p) om::MetaTypeAttribScalar<float>(((char*)((char*)&DAT_004e635c + 4)), "mHalListenerEffect.hFReference", 0x54, 20.0f, 20000.0f, 20.0f, "HF Reference", &DAT_003f335c);
    }
    Registry_24df00* reg = ((Registry_24df00*)&DAT_004e6468);
    reg->v0();
}

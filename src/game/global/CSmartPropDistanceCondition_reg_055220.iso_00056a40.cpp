// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00055220..0x00056af0 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00056a40 FUN_00056a40 (176 B): equivalent/0x00056a40.cpp [isolated: compile error C2664: 'fn_00056a40::fight::ParamEnumConstList<T>::ParamEnumConstList(const char *,const char ** ,int,void (__thiscall CGrapple]
// sym: _FUN_00056a40 @a4c933aeb9f1 @w536522fe2a43
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00056a40 @ 0x00056a40
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CGrappleCharacterTemplateCondition {
public:
    void FUN_00048020();
    void FUN_00048030();
};

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00056a40()
{
    if (DAT_004dc51c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<::CGrappleCharacterTemplateCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<::CGrappleCharacterTemplateCondition>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &::CGrappleCharacterTemplateCondition::FUN_00048020);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList<::CGrappleCharacterTemplateCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList<::CGrappleCharacterTemplateCondition>("characterTemplate", &::CGrappleCharacterTemplateCondition::FUN_00048030);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc518), params, 2);
    }
    DAT_004dc51c++;
}


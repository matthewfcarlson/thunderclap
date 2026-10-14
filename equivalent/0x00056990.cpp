// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00056990 @ 0x00056990
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CCharacterTemplateVariationCondition {
public:
    void FUN_00048000();
    void FUN_00048010();
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
extern ParamRegistry DAT_004dc510;
extern int DAT_004dc514;

extern const char* DAT_00427758[1];

extern int DAT_00427760;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00056990()
{
    if (DAT_004dc514 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<::CCharacterTemplateVariationCondition>("compare", DAT_00427758, DAT_00427760, &::CCharacterTemplateVariationCondition::FUN_00048000);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList<::CCharacterTemplateVariationCondition>("CharacterTemplateVariation", &::CCharacterTemplateVariationCondition::FUN_00048010);
        FUN_002347b0(&DAT_004dc510, params, 2);
    }
    DAT_004dc514++;
}

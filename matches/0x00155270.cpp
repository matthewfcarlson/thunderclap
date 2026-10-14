inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
extern unsigned int DAT_004e1044, DAT_004e1040, DAT_00427760, DAT_003f5eb4;
extern char DAT_00427758, DAT_0048f6b4;
extern void FUN_0014c4d0();
extern void FUN_0014c4e0();
extern void* __cdecl FUN_0008d690(unsigned int);
namespace hulkfight {
namespace motion {
class CollisionSourceSizeCondition;
}
} // namespace hulkfight
struct Base_155270 {
    virtual void slot0();
    char pad[12];
    void FUN_00234cc0(const char*);
};
namespace fight {
template <class T> struct ParamEnumConstList : Base_155270 {
    virtual void slot0();
    void* entries;
    unsigned int count;
    void (*callback)();
    unsigned int tail;
};
} // namespace fight
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition> Param;
extern void __cdecl FUN_002347b0(void*, Param**, unsigned int);
void FUN_00155270() {
    if (DAT_004e1044 == 0) {
        Param* params[2];
        void* mem = FUN_0008d690(32);
        if (mem) {
            unsigned int count = DAT_00427760;
            Base_155270* base = (Base_155270*)mem;
            base->FUN_00234cc0("compare");
            Param* p = new (mem) Param;
            p->entries = &DAT_00427758;
            p->count = count;
            p->callback = FUN_0014c4d0;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690(32);
        if (mem) {
            unsigned int count = DAT_003f5eb4;
            Base_155270* base = (Base_155270*)mem;
            base->FUN_00234cc0("size");
            Param* p = new (mem) Param;
            p->entries = &DAT_0048f6b4;
            p->count = count;
            p->callback = FUN_0014c4e0;
            params[1] = p;
        } else
            params[1] = 0;
        FUN_002347b0(&DAT_004e1040, params, 2);
    }
    ++DAT_004e1044;
}

typedef unsigned int uint;
void* __cdecl FUN_0008d690(uint);
extern uint DAT_004e1074;
extern uint DAT_004e1070;
extern uint DAT_00427760;
extern uint DAT_003f5eb4;
extern uint DAT_00427758;
extern uint DAT_0048f6b4;
void FUN_0014c580();
void FUN_0014c590();
inline void* operator new(unsigned int, void* p) {
    return p;
}
namespace hulkfight {
namespace motion {
class CollisionTargetSizeCondition;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamEnumConstList {
    virtual void slot0();
    char padding[12];
    void* values;
    uint count;
    void (*callback)();
    uint tail;
    void FUN_00234cc0(const char*);
};
} // namespace fight
typedef fight::ParamEnumConstList<hulkfight::motion::CollisionTargetSizeCondition> List_1555c0;
void __cdecl FUN_002347b0(uint*, List_1555c0**, int);
void __cdecl FUN_001555c0() {
    if (!DAT_004e1074) {
        List_1555c0* lists[2];
        void* memory = FUN_0008d690(32);
        if (memory) {
            List_1555c0* p = (List_1555c0*)memory;
            uint count = DAT_00427760;
            p->FUN_00234cc0("compare");
            p = new (memory) List_1555c0;
            p->values = &DAT_00427758;
            p->count = count;
            p->callback = FUN_0014c580;
            lists[0] = p;
        } else
            lists[0] = 0;
        memory = FUN_0008d690(32);
        if (memory) {
            List_1555c0* p = (List_1555c0*)memory;
            uint count = DAT_003f5eb4;
            p->FUN_00234cc0("size");
            p = new (memory) List_1555c0;
            p->values = &DAT_0048f6b4;
            p->count = count;
            p->callback = FUN_0014c590;
            lists[1] = p;
        } else
            lists[1] = 0;
        FUN_002347b0(&DAT_004e1070, lists, 2);
    }
    ++DAT_004e1074;
}

typedef unsigned int uint;
extern uint DAT_004e124c;
extern uint DAT_004e1248;
extern uint DAT_00427760;
extern uint DAT_003f5bbc;
extern uint DAT_00427758;
extern uint DAT_0048f590;
void __cdecl FUN_001656c0();
void __cdecl FUN_001656d0();
void* __cdecl FUN_0008d690(uint);
void __cdecl FUN_002347b0(void*, void*, uint);
inline void* operator new(unsigned int, void* p) {
    return p;
}
namespace hulkfight {
namespace motion {
class TargetLocomotionMotionStateCondition;
}
} // namespace hulkfight
namespace fight {
template <class T> struct ParamEnumConstList {
    virtual void slot0();
    char padding[12];
    void* values;
    uint count;
    void(__cdecl* callback)();
    uint extra;
    void FUN_00234cc0(const char*);
};
} // namespace fight
typedef fight::ParamEnumConstList<hulkfight::motion::TargetLocomotionMotionStateCondition> List;
void __cdecl FUN_0016b650() {
    if (!DAT_004e124c) {
        List* lists[2];
        void* p = FUN_0008d690(32);
        if (p) {
            uint n = DAT_00427760;
            ((List*)p)->FUN_00234cc0("compare");
            List* x = new (p) List;
            x->values = &DAT_00427758;
            x->count = n;
            x->callback = FUN_001656c0;
            lists[0] = x;
        } else
            lists[0] = 0;
        p = FUN_0008d690(32);
        if (p) {
            uint n = DAT_003f5bbc;
            ((List*)p)->FUN_00234cc0("locomotionMotionState");
            List* x = new (p) List;
            x->values = &DAT_0048f590;
            x->count = n;
            x->callback = FUN_001656d0;
            lists[1] = x;
        } else
            lists[1] = 0;
        FUN_002347b0(&DAT_004e1248, lists, 2);
    }
    ++DAT_004e124c;
}

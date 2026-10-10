// action.cpp rewritten against the generated headers (include/gen/). Verify with:
//   build/venv/bin/python tools/compare.py experiments/first-matches/action_gen.cpp 0x13950 vfunc_5
//   build/venv/bin/python tools/compare.py experiments/first-matches/action_gen.cpp 0x14900 vfunc_9
#include <gen/global.h>

// FUNCTION: 0x00013950 (CAction::vfunc_5) -- dispatch on type to slots 7/8
bool CAction::vfunc_5(int type, int arg) {
    bool result = false;
    switch (type) {
    case 0: result = vfunc_7(arg); break;
    case 1: result = vfunc_8(arg); break;
    }
    return result;
}

// The object at +0x1c isn't identified yet: a local stand-in for its slot 3.
struct Info { char pad[0x58]; float value; };
class Source { public: virtual void a(); virtual void b(); virtual void c(); virtual Info* GetInfo(); };

extern const float kDefaultValue;

// FUNCTION: 0x00014900 (CHitAnimationAction::vfunc_9)
float CHitAnimationAction::vfunc_9() {
    Info* info = static_cast<Source*>(f_1c)->GetInfo();
    if (info == 0) return kDefaultValue;
    return info->value;
}

// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,bool,bool,bool,float>::vfunc_2 @ 0x0009c640
#include "gen/global.h"

struct CCameraManager_9c640 { void FUN_0009c640(unsigned int, unsigned int, unsigned int, float); };
struct Arguments { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; char pad2[3]; float fourth; };

template <> void Closure4<CCameraManager, void, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; Arguments * arguments = (Arguments *)__p1; int unused2 = (int)__p2;

    unsigned int first = (reinterpret_cast<unsigned int>(this) & 0xffffff00u) | arguments->first;
    unsigned int second = (reinterpret_cast<unsigned int>(arguments) & 0xffffff00u) | arguments->second;
    ((*(CCameraManager_9c640 * *)&this->f_20)->*(*(void (CCameraManager_9c640::**)(unsigned int, unsigned int, unsigned int, float))&this->f_1c))(first, second, arguments->third, arguments->fourth);
}

// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CCameraManager,void,int,int,float,int,int,float>::vfunc_2 @ 0x0009c960
#include "compat/ptr.h"
#include "gen/global.h"

struct CCameraManager_9c960 { void FUN_0009c960(int, int, float, int, int, float); };
struct Arguments { int first; int second; float third; int fourth; int fifth; float sixth; };

template <> void Closure6<CCameraManager, void, int, int, float, int, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * arguments = (Arguments *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    ((*(CCameraManager_9c960 * *)&this->f_20)->*(*(void (CCameraManager_9c960::**)(int, int, float, int, int, float))&this->f_1c))(arguments->first, arguments->second, arguments->third, arguments->fourth, arguments->fifth, arguments->sixth);
}

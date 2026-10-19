// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// FUN_00086450 @ 0x00086450
// cl-flags: /GS
#include "decls/data/game/global.h"

typedef unsigned __int64 U64_86450;
extern "C" U64_86450 __cdecl FUN_00267f40();
struct Debug_86450 { void FUN_0023f720(int*,const char*); bool FUN_0023f760(const char*,int,int); bool FUN_0023f770(const char*,int); int FUN_0023f790(const char*,int,int,int,int); void FUN_0023f740(); };
struct Timer { U64_86450 limit,last,total,scaledTotal,elapsed,step,scaledStep,rate; char pad[8]; unsigned char paused; void FUN_00086450(); };
void Timer::FUN_00086450() {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 step=0; scaledStep=0;
 U64_86450 now=FUN_00267f40(); elapsed=now-last; last=now;
 (*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f720(&DAT_0049c104,"VCR");
 if (!paused && (!(*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f760("Paused",32,0) || (*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f770("Step when paused",115))) {
 step=elapsed<limit?elapsed:limit;
 scaledStep=(rate*step)>>16;
 int dilation=(*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f790("Debug time dilation",93,91,17,16);
 scaledStep=((U64_86450)(__int64)dilation*scaledStep)>>4;
 } else { step=0; scaledStep=0; }
 total+=step; scaledTotal+=scaledStep;
 (*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f740();
}
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 18/18)
// hulkfight::motion::VarAssignAction::vfunc_4 @ 0x0018d0d0
#include "gen/hulkfight.h"

struct Key_18d0d0 { char data[8]; };
struct Config_18d0d0 { char pad[16]; Key_18d0d0 key; unsigned op; unsigned unused; int value; unsigned char enabled; };
struct Vars { int FUN_00036e40(Key_18d0d0*); void FUN_00036e70(Key_18d0d0*, int); };
struct Context_18d0d0 { Vars* FUN_00059a30(); };
struct Owner_18d0d0 { Context_18d0d0* FUN_000592a0(); };
namespace hulkfight { namespace motion {

}}
void hulkfight::motion::VarAssignAction::vfunc_4() {
 Vars* vars = (*(Owner_18d0d0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
 if (!(*(Config_18d0d0 * *)&this->f_1c)->enabled) return;
 int current = vars->FUN_00036e40(&(*(Config_18d0d0 * *)&this->f_1c)->key);
 Config_18d0d0* c = (*(Config_18d0d0 * *)&this->f_1c);
 int v = c->value;
 int result;
 switch(c->op) {
 case 0: result = v; break;
 case 1: result = (int)((unsigned)current + (unsigned)v); break;
 case 2: result = (int)((unsigned)current - (unsigned)v); break;
 case 3: result = (int)((unsigned)current * (unsigned)v); break;
 case 4: result = v ? current / v : 0; break;
 case 5: result = v ? current % v : 0; break;
 case 6: result = (int)((unsigned)current + 1); if(v) result %= v; break;
 case 7: result = (int)((unsigned)current + (unsigned)v - 1); if(v) result %= v; break;
 default: return;
 }
 vars->FUN_00036e70(&c->key, result);
}

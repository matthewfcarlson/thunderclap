// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 18/18)
// hulkfight::motion::VarAssignAction::vfunc_4 @ 0x0018d0d0
struct Key_18d0d0 { char data[8]; };
struct Config_18d0d0 { char pad[16]; Key_18d0d0 key; unsigned op; unsigned unused; int value; unsigned char enabled; };
struct Vars { int FUN_00036e40(Key_18d0d0*); void FUN_00036e70(Key_18d0d0*, int); };
struct Context { Vars* FUN_00059a30(); };
struct Owner_18d0d0 { Context* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct VarAssignAction { char pad[28]; Config_18d0d0* config; Owner_18d0d0* owner; void vfunc_4(); };
void VarAssignAction::vfunc_4() {
 Vars* vars = owner->FUN_000592a0()->FUN_00059a30();
 if (!config->enabled) return;
 int current = vars->FUN_00036e40(&config->key);
 Config_18d0d0* c = config;
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
}}

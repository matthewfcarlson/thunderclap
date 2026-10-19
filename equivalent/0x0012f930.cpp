// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// hulkfight::NISSoundAction::vfunc_3 @ 0x0012f930
// hulkfight::NISSoundAction::vfunc_3 @ 0x0012f930
struct SoundValue { unsigned int data[2]; void FUN_0027b0e0(unsigned int); void FUN_0027af50(); };
struct SoundInfo { char pad[16]; unsigned int sound; unsigned int value; unsigned int extra; };
struct SoundSystem {};
struct SoundHandle { void FUN_001eb5e0(SoundValue *, unsigned int, unsigned int); };
extern SoundSystem *DAT_004dd6ec;
SoundHandle *__fastcall FUN_000862e0(SoundSystem *);
namespace hulkfight {
struct NISSoundAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c-4]; SoundInfo *info; unsigned int enabled;
};
bool NISSoundAction::vfunc_3(int, int) {
 if (!enabled) return false;
 SoundValue value;
 value.FUN_0027b0e0(info->value);
 unsigned int extra = info->extra;
 unsigned int sound = info->sound;
 SoundHandle *handle = FUN_000862e0(DAT_004dd6ec);
 handle->FUN_001eb5e0(&value, sound, extra);
 value.FUN_0027af50();
 return true;
}
}

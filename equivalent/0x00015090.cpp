// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// CSweepAction::vfunc_7 @ 0x00015090
struct Value_15090 { float FUN_000354c0(); };
struct Link_15090 { Value_15090* FUN_00059a30(); };
struct Actor_15090 { Link_15090* FUN_000592a0(); };
struct Timing_15090 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7();
 char pad[16]; float duration;
};
struct Output_15090 { void FUN_00221d20(float); };
struct Destination_15090 { char pad[24]; Output_15090 output; };
struct CSweepAction {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual bool vfunc_7(float); virtual void slot8();
 char pad[24]; Actor_15090* actor; Timing_15090* timing; Destination_15090* destination; float progress;
};
bool CSweepAction::vfunc_7(float step) {
 if (!destination) return false;
 float base = actor->FUN_000592a0()->FUN_00059a30()->FUN_000354c0();
 float duration = timing->duration;
 float rate = timing->slot7();
 if (rate <= 0.0f) { destination->output.FUN_00221d20(duration + base); return false; }
 step = (duration / rate) * step;
 if (duration < 0.0f) {
  if (step + progress < duration) step = duration - progress;
 } else {
  if (step + progress > duration) step = duration - progress;
 }
 destination->output.FUN_00221d20(step + base);
 progress = step + progress;
 return true;
}
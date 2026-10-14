// STATUS: equivalent (tools/equiv.py level 3: 182 inputs, branch coverage 44/46, incomplete)
// FUN_000bdf50 @ 0x000bdf50
struct State_bdf50 { int buttons[35]; struct Stick { unsigned int axis[2]; int unused[2]; } sticks[2]; };
struct Device_bdf50 { void FUN_000af0f0(State_bdf50*); };
struct Input_bdf50 { Device_bdf50* FUN_000af3a0(int); };
struct Manager_bdf50 { Input_bdf50* FUN_000862d0(); };
struct Root_bdf50 { char pad[0x54]; Manager_bdf50* manager; };
extern Root_bdf50* DAT_004dd700;
struct Action { void FUN_000de9a0(int); };
struct System_bdf50 { char pad[0x182c]; Action* action; };
System_bdf50* __cdecl FUN_000fc3d0();
struct Target_bdf50 {
 char pad[0x1a04]; unsigned char flag; unsigned char latched;
 bool FUN_000bdf50(bool mode, bool analog);
};
bool Target_bdf50::FUN_000bdf50(bool mode, bool analog) {
 if (!DAT_004dd700 || !DAT_004dd700->manager || !DAT_004dd700->manager->FUN_000862d0()) return false;
 Input_bdf50* input = DAT_004dd700->manager->FUN_000862d0();
 State_bdf50 state;
 input->FUN_000af3a0(0)->FUN_000af0f0(&state);
 if (!mode) {
  if (state.buttons[0] == 1 || state.buttons[12] == 1 || state.buttons[3] == 1 || state.buttons[18] == 1) return true;
  if (analog) {
   for (int stick = 0; stick < 2; ++stick) {
    for (int axis = 0; axis < 2; ++axis) {
     union { unsigned int bits; float value; } magnitude;
     magnitude.bits = state.sticks[stick].axis[axis] & 0x7fffffffU;
     if (magnitude.value > 0.1f) return true;
    }
   }
  }
  return false;
 }
 if (latched) {
  if (state.buttons[3] == 3 || state.buttons[18] == 3) {
   latched = 0;
   return true;
  }
  return false;
 }
 if (state.buttons[3] == 1 || state.buttons[18] == 1) {
  flag = 1;
  latched = 1;
  FUN_000fc3d0()->action->FUN_000de9a0(1);
  return false;
 }
 if (state.buttons[0] == 1 || state.buttons[12] == 1) return latched == 0;
 return false;
}
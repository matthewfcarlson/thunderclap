// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 8/8)
// FUN_0021ee70 @ 0x0021ee70
struct State_21ee70 { int unknown; int position; int previous; int token; int value; int savedToken; int savedValue; void* context; };
// equiv-conv: FUN_0021ede0 eax
int FUN_0021ede0(State_21ee70* state);
int __cdecl FUN_00220cd0(void* context);
void __cdecl FUN_002207c0(void* context, int* result, int value);
void __cdecl FUN_00220d70(void* context, int value);
// equiv-conv: FUN_0021e080 eax
void FUN_0021e080(State_21ee70* state);
int __cdecl FUN_0021bbc0(State_21ee70* state, int* value);
// equiv-conv: FUN_0021c340 eax esi edi stack
int FUN_0021c340(int argument, State_21ee70* state, int token, int mode);
// equiv-conv: FUN_0021ee70 eax stack
int __cdecl FUN_0021ee70(State_21ee70* state, int argument) {
 void* context = state->context;
 int result = -1;
 int value = FUN_0021ede0(state);
 while (state->token == 0x105) {
  int current = FUN_00220cd0(context);
  FUN_002207c0(context, &result, current);
  FUN_00220d70(context, value);
  value = FUN_0021ede0(state);
 }
 if (state->token == 0x104) {
  int current = FUN_00220cd0(context);
  FUN_002207c0(context, &result, current);
  FUN_00220d70(context, value);
  int saved = state->savedToken;
  state->previous = state->position;
  if (saved != 0x11f) {
   int savedValue = state->savedValue;
   state->savedToken = 0x11f;
   state->token = saved;
   state->value = savedValue;
  } else {
   state->token = FUN_0021bbc0(state, &state->value);
  }
  FUN_0021e080(state);
 } else {
  FUN_002207c0(context, &result, value);
 }
 FUN_00220d70(context, result);
 return FUN_0021c340(argument, state, 0x106, 0x10a);
}
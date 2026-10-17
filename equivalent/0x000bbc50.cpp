// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000bbc50 @ 0x000bbc50
struct Inner { char pad[0x54]; void *value; };
struct Object { char pad[4]; Inner *inner; void FUN_000bbc50(float input); };
extern float DAT_003f3358;
extern float DAT_00407b04;
extern float DAT_00406130;
void __cdecl FUN_001b8750(float value);
void Object::FUN_000bbc50(float input) {
    if (inner && inner->value) {
        FUN_001b8750(input * DAT_003f3358 * DAT_00407b04 + DAT_00406130);
    }
}
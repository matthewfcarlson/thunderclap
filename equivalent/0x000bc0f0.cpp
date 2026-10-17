// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 0/0)
// FUN_000bc0f0 @ 0x000bc0f0
struct Inner { char pad[16]; int value; };
struct Object { char pad[4]; Inner* inner; int FUN_000bc0f0(int a, int b); };
int Object::FUN_000bc0f0(int a, int b) {
    inner->value = 16;
    return 0;
}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0027beb0 @ 0x0027beb0
struct Limb { virtual void unused(); char pad[12]; int value; }; struct Wrapper { void FUN_0027be00(void*, Limb*); void FUN_0027beb0(void* arg); }; void Wrapper::FUN_0027beb0(void* arg) { Limb limb; limb.value = 0; FUN_0027be00(arg, &limb); }
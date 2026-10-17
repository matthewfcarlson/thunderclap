// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00082cf0 @ 0x00082cf0
struct Recipient { void FUN_001dc3b0(int); }; struct Global { char pad[12]; Recipient* recipient; }; extern Global* DAT_004dd700; struct Owner { char pad[16]; int value; void FUN_00082cf0(); }; void Owner::FUN_00082cf0() { DAT_004dd700->recipient->FUN_001dc3b0(value); }
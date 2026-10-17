// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 2/2)
// FUN_000373a0 @ 0x000373a0
struct Character { char pad[0x20b8]; char name[5]; unsigned char FUN_000373a0(int unused); }; unsigned char Character::FUN_000373a0(int unused) { for (int i = 0; i < 5; ++i) { if (name[i] != "hulk"[i]) return 0; } return 1; }
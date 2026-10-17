// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f9980 @ 0x000f9980
struct FUN_0027b070 { FUN_0027b070(); virtual void dummy(); char pad[12]; int first; int second; int third; }; struct Raw : FUN_0027b070 { Raw(int a, int b); }; Raw::Raw(int a, int b) { first=a; third=a; second=b; }
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9b30 @ 0x001c9b30
struct Args { unsigned x,y; void FUN_0027af50(); };
struct Task { unsigned type, kind, a, b, c, d, arg1, arg2; Task * FUN_001c9b30(unsigned x, unsigned y); };
Task * Task::FUN_001c9b30(unsigned x, unsigned y) {
 type=0; kind=0; a=0; b=0; c=0; d=0; arg1=0; arg2=0;
 type=32; kind=5; arg1=x; arg2=y;
 ((Args *)&x)->FUN_0027af50();
 return this;
}
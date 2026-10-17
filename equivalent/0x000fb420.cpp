// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 0/0)
// FUN_000fb420 @ 0x000fb420
struct Vec3 { unsigned int x, y, z; };
struct Destination { char pad0[0x3c]; unsigned int value; char pad1[0x38]; Vec3 position; };
struct Source { unsigned int state; Destination *destination; char pad0[0x18]; Vec3 position; unsigned int pad1; unsigned int value; void FUN_000fb420(); };
void Source::FUN_000fb420() { destination->value = value; destination->position = position; state = 0; }
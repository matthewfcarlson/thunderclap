// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d4c90 @ 0x001d4c90
struct Object { Object* FUN_001d4830(); }; extern Object* DAT_004e23cc; void* __cdecl FUN_0008d690(unsigned int); void FUN_001d4c90() { if (!DAT_004e23cc) { void* memory = FUN_0008d690(0x5494); if (memory) DAT_004e23cc = ((Object*)memory)->FUN_001d4830(); else DAT_004e23cc = 0; } }
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000fa0b0 @ 0x000fa0b0
struct Source { char pad[4]; unsigned int a,b,c,d; unsigned char byte0,byte1; void FUN_000fa0b0(unsigned int *out); }; void Source::FUN_000fa0b0(unsigned int *out) { out[0]=a; out[1]=b; out[2]=c; out[3]=d; out[4]=0x5a5a0000u | (unsigned int)byte1 | ((unsigned int)byte0<<8); }
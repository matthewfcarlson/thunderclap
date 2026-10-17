// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8)
// FUN_002dd2e0 @ 0x002dd2e0
struct Data { char pad[4]; unsigned int length; unsigned char flag; unsigned char mode; }; void __cdecl FUN_002dd2e0(Data* data, unsigned char* bytes) { if (data->mode == 1 && data->flag == 0) { for (unsigned int i = 0; i < data->length; ++i) bytes[i] = ~bytes[i]; } }
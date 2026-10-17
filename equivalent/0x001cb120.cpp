// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cb120 @ 0x001cb120
struct Data { int kind; int a; int b; int c; int d; char rest[0xc0]; }; Data* __fastcall FUN_001cb120(Data* value) { char* bytes = (char*)value; for (int i=0; i<0xe0; ++i) bytes[i]=0; value->kind=0x14; return value; }
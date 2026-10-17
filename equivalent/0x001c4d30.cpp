// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c4d30 @ 0x001c4d30
struct Result { unsigned int a,b,c,d; }; void __stdcall FUN_001c4b50(Result*); void __stdcall FUN_001c4d30(Result* out) { Result temp; FUN_001c4b50(&temp); out->a=temp.a; out->b=temp.b; out->c=temp.c; }
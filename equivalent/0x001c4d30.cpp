// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c4d30 @ 0x001c4d30
struct Result { unsigned int a,b,c,d; }; struct Locator_1c4d30 { void FUN_001c4b50(Result*); void FUN_001c4d30(Result* out); }; void Locator_1c4d30::FUN_001c4d30(Result* out) { Result temp; FUN_001c4b50(&temp); out->a=temp.a; out->b=temp.b; out->c=temp.c; }
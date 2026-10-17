// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00099570 @ 0x00099570
struct Triple { int a,b,c; }; struct Object { void FUN_00099500(int, int, Triple, int); void FUN_00099570(int a,int b,int c,int d,int e,int f); }; void Object::FUN_00099570(int a,int b,int c,int d,int e,int f) { Triple t; t.a=c; t.b=d; t.c=e; FUN_00099500(a,b,t,f); }
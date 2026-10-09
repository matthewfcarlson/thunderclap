typedef unsigned char u8;
struct Obj { char pad[0x14]; u8 flag; };
struct H { H* f1(); void f2(); H* f3(); void f4(); };
H* g();
struct TokenSupressAction { char pad0[0x1c]; Obj* data; H* active; bool vfunc_5(int a,int b); };
bool TokenSupressAction::vfunc_5(int a,int b) {
 if (!active) return false;
 active->f1()->f2();
 if(data->flag) g()->f4();
 return true;
}

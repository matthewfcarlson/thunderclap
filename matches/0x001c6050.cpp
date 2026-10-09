struct Item { char pad[0x23]; char flag; };
struct Holder { Item* Find(int); };
struct Obj { char pad[12]; Holder* h; void Poke(); };
struct Sub { char pad[8]; void Init(); void Set(int); };
Obj* __stdcall Make2(int a, int b);
Obj* __stdcall Make0();
struct Owner {
 void* vf; char pad[4]; Sub s; int b;
 Owner* Target(int arg1, int arg2);
};
Owner* Owner::Target(int arg1, int arg2) {
 vf = (void*)0x421990;
 s.Init();
 s.Set(arg1);
 Obj* o = Make2(arg1, arg2);
 o->Poke();
 Obj* p = Make0();
 Holder* h = p->h;
 Item* it = h->Find(arg1);
 b = (int)it;
 it->flag = 1;
 return this;
}

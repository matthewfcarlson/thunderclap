class A { char pad[16]; public: int Get(); };
class Tmp { char x[64]; public: void Init(); void SetArg(int); void SetPtr(int); };
class Obj { char pad[16]; public: bool target(int); bool Run(Tmp*); };
bool Obj::target(int arg) {
 int p = ((A*)*(int*)((char*)this+0x10))->Get();
 if (!p) return false;
 Tmp t;
 t.Init(); t.SetArg(arg); t.SetPtr(p+0x40);
 return Run(&t);
}

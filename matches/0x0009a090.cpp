class Obj { public: virtual void F0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7(); virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15(); virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19(); virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23(); virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27(); virtual void F28(); };
void* __cdecl Alloc(int);
Obj* __fastcall Construct(void* mem);
class Owner { public: char p0[0x10]; void* other; char p1[0xa4]; Obj* item; void Prep(); void Run(); };
void Owner::Run() { Prep(); void* m = Alloc(0x4c0); item = m ? Construct(m) : 0; item->F0(); item->F28(); other = item; }

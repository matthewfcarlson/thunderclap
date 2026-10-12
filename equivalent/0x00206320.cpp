// STATUS: equivalent (tools/equiv.py level 3: 180 inputs, branch coverage 42/42)
// FUN_00206320 @ 0x00206320
struct Obj {
  virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
  void FUN_00263e90(); void FUN_002660a0(Obj*);
};
struct Alloc { Obj* FUN_00266480(int); };
struct Sub { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Ctx {
  char pad0[0x80]; Sub sub;
  const char* FUN_000897e0(); char* FUN_000897f0(); char* FUN_0008a2d0();
};
struct Prov { Ctx* FUN_00086310(); };
struct Rand { int FUN_00011380(int, int); };
struct Link { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); void FUN_00233160(Obj*); };
struct Node { char pad[0x5c]; Link* link; };
struct Registry { void FUN_001d3600(const char*, int); };
struct Fig { Obj* FUN_00024400(const char*, int); };
struct Game { char pad[0x20]; Fig* fig; };
struct Timer { void FUN_00265ad0(); void FUN_00264860(int); };
struct Nodes {
  Node* FUN_00232840(long long); int FUN_002327c0(); Node* FUN_00232810(int);
};
struct W {
  char pad0[4]; char name1[0x20]; char name2[0x20];
  Obj* f44;
  char pad1[0x588-0x48]; Prov* prov;
  char pad2[0x5a4-0x58c]; unsigned int tbl[0x100];
  char pad3[0xaa0-0x9a4]; Obj* aa0; char aa4[0x20]; char ac4[0x20];
  Obj* ae4; Obj* ae8;
  void FUN_00205910(); void FUN_00203a10(); void FUN_00203870(const char*); void FUN_002039a0(int, int);
  Obj* FUN_00203e90(const char*, int, int, int, Obj*, Obj*, int);
  void FUN_00206320(Ctx*);
};
extern "C" unsigned int DAT_004d9968;
extern "C" Timer* DAT_00527c58;
extern "C" Game* DAT_004dd700;
extern "C" Nodes* DAT_004e5af8;
extern "C" const char* DAT_004c91cc;
extern "C" const char* DAT_004c91d4;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" Registry* __cdecl FUN_001d4c90();
extern "C" Rand* __cdecl FUN_000964d0();
extern "C" long long __cdecl FUN_002672f0(const char*, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00266da0(int);
extern "C" int __cdecl FUN_002381a0(int, int);
extern "C" void* __cdecl FUN_00263ea0(int);
extern "C" void __cdecl FUN_000964a0(char*, int, const char*, ...);
extern "C" char* __cdecl _strncpy(char*, const char*, unsigned int);
extern "C" int __cdecl _strncmp(const char*, const char*, unsigned int);
void W::FUN_00206320(Ctx* g){
  unsigned int cookie = DAT_004d9968;
  char buf[0x100];
  const char* s = prov->FUN_00086310()->FUN_000897e0();
  char* d = name1;
  while ((*d++ = *s++) != 0) {}
  s = prov->FUN_00086310()->FUN_000897f0();
  d = name2;
  while ((*d++ = *s++) != 0) {}
  DAT_00527c58->FUN_00265ad0();
  DAT_00527c58->FUN_00264860(3000);
  FUN_00205910();
  for (int i = 0; i < 0x100; i++) tbl[i] = 0;
  Registry* reg = FUN_001d4c90();
  FUN_00203a10();
  if (prov->FUN_00086310()->sub.FUN_00088fa0() == 10) {
    const char* hulk = "hulk";
    bool same = true;
    for (int i = 0; i < 5; i++) if (aa4[i] != hulk[i]) { same = false; break; }
    if (same) {
      int v = prov->FUN_00086310()->sub.FUN_00088fb0();
      if (v == 0x20 || v == 0x28) {
        FUN_00203870("joefixit");
      } else if (v == 0x23) {
        FUN_002039a0(5, 12);
        int r = FUN_000964d0()->FUN_00011380(1, 10);
        if (r == 1) FUN_00203870("hulk_canada");
        else if (r == 2) FUN_00203870("hulk_australia");
      }
    }
  }
  if (aa0 != 0 && _strncmp(aa4, ac4, 0x20) == 0) {
    Nodes* nodes = DAT_004e5af8;
    Node* n1 = nodes->FUN_00232840(FUN_002672f0(DAT_004c91cc, 0, 0));
    Link* l1 = n1->link;
    l1->FUN_00233160(ae4);
    Node* n2 = nodes->FUN_00232840(FUN_002672f0(DAT_004c91d4, 0, 0));
    Link* l2 = n2->link;
    l2->FUN_00233160(ae8);
  } else {
    int savedHeap = FUN_00266da0(0x11);
    if (ae8) { ae8->slot1(); ae8 = 0; }
    if (ae4) { ae4->slot1(); ae4 = 0; }
    if (aa0) { aa0->slot1(); aa0 = 0; }
    void* mem = FUN_00263ea0(0x14);
    aa0 = mem ? ((Alloc*)mem)->FUN_00266480(0x800) : 0;
    aa0->slot0();
    FUN_000964a0(buf, 0x100, "art/global_nonchar.p3d");
    FUN_00203e90(buf, 0, 1, 0, aa0, 0, 0x11)->FUN_00263e90();
    FUN_000964a0(buf, 0x100, "art/global_%s.p3d", aa4);
    FUN_00203e90(buf, 0, 1, 0, aa0, 0, 0x11)->FUN_00263e90();
    _strncpy(ac4, aa4, 0x20);
    Fig* fig = DAT_004dd700->fig;
    int oldMode = FUN_002381a0(2, 0x11);
    Obj* o = fig->FUN_00024400("scripts/fight/hulk.fig", 0);
    if (o) o->slot0();
    if (ae4) ae4->slot1();
    ae4 = o;
    o = fig->FUN_00024400("scripts/fight/common.fig", 0);
    if (o) o->slot0();
    if (ae8) ae8->slot1();
    ae8 = o;
    FUN_002381a0(2, oldMode);
    FUN_00266da0(savedHeap);
  }
  FUN_000964a0(buf, 0x100, "art/locations/%s/%s_init.lua", g->FUN_000897e0(), g->FUN_000897f0());
  reg->FUN_001d3600(buf, 0);
  FUN_000964a0(buf, 0x100, "art/missions/%s/%s_init.lua", g->FUN_0008a2d0(), g->FUN_0008a2d0());
  reg->FUN_001d3600(buf, 0);
  Nodes* nodes = DAT_004e5af8;
  int n = nodes->FUN_002327c0();
  for (int i = 0; i < n; i++) nodes->FUN_00232810(i)->link->slot5();
  f44->FUN_002660a0(aa0);
  FUN_000964a0(buf, 0x100, "art/locations/%s/%s.p3d", g->FUN_000897e0(), g->FUN_000897f0());
  FUN_00203e90(buf, 0, 1, 0, f44, f44, 0xb)->FUN_00263e90();
  FUN_000964a0(buf, 0x100, "art/missions/%s/%s.p3d", g->FUN_0008a2d0(), g->FUN_0008a2d0());
  FUN_00203e90(buf, 0, 1, 0, f44, f44, 0xb)->FUN_00263e90();
  __security_check_cookie(cookie);
}

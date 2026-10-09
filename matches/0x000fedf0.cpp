extern int CActorGolem_vftable;
class CActorGolem { public: virtual void f(); char pad[0xf4]; void* m; void InitBase(); CActorGolem* Init(void*); };
CActorGolem* CActorGolem::Init(void* p) { InitBase(); m = p; *(int*)this = (int)&CActorGolem_vftable; return this; }
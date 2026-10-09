extern void* vtController;
extern void* vtDolly;
void __cdecl Release(void*);
class State { public: void* vt; char pad[8]; void* a; void* b; void Clear(); };
void State::Clear() { vt=&vtController; if(a){ Release(a); a=0; } if(b){ Release(b); b=0; } vt=&vtDolly; }
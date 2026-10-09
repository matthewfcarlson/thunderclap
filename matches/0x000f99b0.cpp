extern int rawVtable;
class CRawScript { public: int* vptr; char pad[12]; int mArg; void finish(); void run(); };
extern void __cdecl thunk(int);
void CRawScript::run() { vptr = &rawVtable; thunk(mArg); finish(); }
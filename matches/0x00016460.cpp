class CAction { char pad[0x1c]; };
class CSmartPropThrowingAction : public CAction { public: void vfunc_4(); };
struct HelperA { char pad[0x1c]; HelperA* f(); char* g(); };
void CSmartPropThrowingAction::vfunc_4() {
    HelperA* p = *(HelperA**)((char*)this + 0x1c);
    p = p->f();
    char* q = p->g();
    q[0x1f51] = 0;
}
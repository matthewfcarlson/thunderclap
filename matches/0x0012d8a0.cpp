class ThreatDodgeTrack { public: int a[2]; int b; int c; int d; char e[4]; int f; };
extern void* __cdecl Alloc(int);
struct Base { Base(); }; struct Tail { Tail(); };
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual ThreatDodgeTrack* Create(); };
ThreatDodgeTrack* Factory::Create() {
    ThreatDodgeTrack* p = (ThreatDodgeTrack*)Alloc(0x28);
    if (p) {
        Base* b = (Base*)p; b->Base::Base();
        *(int*)p = 0x410c84;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0xbf800000;
        *(int*)((char*)p + 0x14) = 0x3f800000;
        *((char*)p + 0x18) = 1;
        Tail* t = (Tail*)((char*)p+0x20); t->Tail::Tail();
        return p;
    }
    return 0;
}
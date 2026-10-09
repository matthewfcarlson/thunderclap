class Base { public: Base(); virtual void bv(); int bx; };
class CSoundTrack : public Base { public: CSoundTrack() : Base() { zero = 0; flag = 0; flag2 = 0; one = 1; } virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); int one; int zero; unsigned char flag; char pad[0x3f]; unsigned char flag2; };
void* operator_new(unsigned int);
class TrackFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual CSoundTrack* make(); };
CSoundTrack* TrackFactoryTemplate::make() { CSoundTrack* p = (CSoundTrack*)operator_new(0x54); if (p) { p->CSoundTrack::CSoundTrack(); return p; } return 0; }

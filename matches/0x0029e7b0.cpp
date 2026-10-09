extern void* LightsChooserCache_vftable;
class Helper { public: void Finish(); };
class LightsChooserCache { public: virtual void a(); virtual void b(); virtual LightsChooserCache* vfunc_2(unsigned char); virtual void c(); virtual void d(); char pad[0x20]; void* member; };
void ReleaseThing(void*);
LightsChooserCache* LightsChooserCache::vfunc_2(unsigned char param) { *(void**)this = &LightsChooserCache_vftable; ReleaseThing(member); ((Helper*)this)->Finish(); if (param & 1) ReleaseThing(this); return this; }
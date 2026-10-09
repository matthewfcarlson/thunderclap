class Mid { public: Mid* Touch(); void Draw(float, int, int, int, int, unsigned char); };
class Thing { public: virtual void a(); virtual void b(); virtual void c(); virtual int d(); char pad[0x48-4]; int x48; int x4c; char p[0x78-0x50]; float x78; int x7c; char p2[0x91-0x80]; unsigned char x91; };
class Ref { public: virtual void a(); virtual void b(); virtual void c(); virtual Thing* d(); Mid* GetSub(); };
class HitDamageAction { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual unsigned char v3(int, int); virtual void v4(); virtual void v5(); char pad1[0x1c-4]; void* p1c; Ref* p20; };
unsigned char HitDamageAction::v3(int, int) {
    if (p20) {
        Thing* t = p20->d();
        if (t) {
            Mid* m = p20->GetSub()->Touch();
            m->Draw(*(float*)((char*)p1c + 0x10) * t->x78, t->x4c, t->x48, t->x7c, 0, t->x91);
        }
    }
    return 0;
}

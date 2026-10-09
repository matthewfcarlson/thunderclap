class NewItem { public: virtual void Dispose(); };
class OldItem { public: virtual void First(); virtual void Release(); };
class Owner { public: char pad[0x64]; OldItem* item; void Set(NewItem* p); };
void Owner::Set(NewItem* p) { if (p) p->Dispose(); if (item) item->Release(); item = (OldItem*)p; }
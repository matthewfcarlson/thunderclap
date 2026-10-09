class Record { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void* f3(); };
class Helper { public: void g(); };
class ClearFightParamsHitRecordAction { char pad[0x1c]; Record* record; public: virtual void f0(); virtual void f1(); virtual void f2(); virtual bool vfunc_3(int, int); };
bool ClearFightParamsHitRecordAction::vfunc_3(int, int) { if (record) { void* p = record->f3(); if (p) { ((Helper*)p)->g(); } } return false; }
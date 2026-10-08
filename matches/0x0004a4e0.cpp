// Same code shape as 0x0004a260 (propagated; names are from that function)
class CCondition { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(void*); };
class CMotionStateCondition : public CCondition { public: virtual void v8(void*); };
struct H { H* first(); void second(); };
void CMotionStateCondition::v8(void* p) { ((H*)p)->first()->second(); }
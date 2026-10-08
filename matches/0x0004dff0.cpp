class CStageCondition;
class ParamValue { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); };
class ParamValueInt : public ParamValue { public: int pad; };
class ParamIntConstRange : public ParamValueInt { public: char padding[8]; int value; bool vfunc_2(); };
bool ParamIntConstRange::vfunc_2() { return value == 0; }
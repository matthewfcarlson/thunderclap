class CStageCondition {};
class ParamValue { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); };
class ParamValueEnum : public ParamValue { public: virtual void f(); };
class ParamEnumConstList : public ParamValueEnum {
public:
 virtual void g();
 virtual void h();
 virtual CStageCondition *i(int, int);
 virtual void j();
 virtual void k();
 char pad[0xc];
 CStageCondition **items;
 int count;
};
extern CStageCondition zeroCondition;
CStageCondition *ParamEnumConstList::i(int, int index) { if (index >= 0 && index < count) return items[index]; return &zeroCondition; }
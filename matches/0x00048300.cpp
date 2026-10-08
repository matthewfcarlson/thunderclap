extern int* gTable;
class CCondition { public: virtual int vfunc_0(int); };
class CStageCondition : public CCondition { public: int vfunc_0(int); };
int CStageCondition::vfunc_0(int index) { int* p = gTable; return p[index]; }

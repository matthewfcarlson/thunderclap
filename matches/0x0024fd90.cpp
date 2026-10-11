class SeqEvent {
  public:
    char vfunc_1(int*);
};
class SeqEventContainer {
  public:
    char vfunc_1(int*);
};
class SeqEventCondition {
  public:
    virtual void v0();
    virtual int vfunc_1(int*);
    char pad[0x10];
};
extern "C" char Parse(const char*, const char*);
extern "C" char Expr(int*, const char*, char*);
int SeqEventCondition::vfunc_1(int* p) {
    if (((SeqEvent*)this)->vfunc_1(p) && Parse((const char*)*p, "\n[\n")) {
        ++*(int*)((char*)*p + 0x24);
        if (((SeqEventContainer*)this)->vfunc_1(p) && Expr(p, "mExpression", (char*)this + 0x14)) {
            --*(int*)((char*)*p + 0x24);
            p = (int*)*p;
            if (Parse((const char*)p, "]\n"))
                return 1;
        }
    }
    return 0;
}

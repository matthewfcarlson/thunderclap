class ConditionFactoryCaster {
  public:
    virtual int check(const char*);
    virtual void other();
};
extern "C" int __cdecl helper(const char*, int, const void*, const void*, int);
extern int a, b;
class EventCaster : public ConditionFactoryCaster {
  public:
    virtual int check(const char*);
    virtual void other();
};
int EventCaster::check(const char* s) {
    return helper(s, 0, &a, &b, 0) != 0;
}
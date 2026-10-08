class Function { public: virtual void v0(); virtual void v1(); };
class Function1 : public Function { char pad[0x18]; public: void (__cdecl *mFn)(const char *); virtual void v0(); virtual void v1(); virtual void v2(int, const char **, int); };
void Function1::v2(int, const char **p, int) { mFn(*p); }
class Local { public: char data[8]; void Init(); void Finish(); };
class Helper { public: void Do(Local*); };
class T {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
 virtual bool Run(int, int, Local*);
 char Target(int a, int b, Helper* h);
};
char T::Target(int a, int b, Helper* h) {
 Local x;
 x.Init();
 bool r = Run(a, b, &x);
 if (r) ((Helper*)((char*)h + 8))->Do(&x);
 x.Finish();
 return r;
}
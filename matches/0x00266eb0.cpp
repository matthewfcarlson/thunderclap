class Entry { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual int Get(int,int); };
struct Slot { Entry* p; char pad[12]; };
extern Slot gEntries[];
typedef int (__cdecl *Callback)(int,int,int,int);
extern Callback gCallback;
extern int gContext;
int Func(int a,int b,int c) { int r=gEntries[a].p->Get(b,c); if(r==0 && gCallback) gCallback(gContext,a,b,c); return r; }
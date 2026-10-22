struct CTriggerVolumeManager;
extern char gA, gB;
char __cdecl getFlag(const char*);
class Function_1ffa60 {
  public:
    Function_1ffa60(const char*, int);
    virtual void f();
    char pad[12];
    char b10;
    char pad2[7];
    char b18;
    char pad3[3];
    CTriggerVolumeManager* owner;
};
class Method1 : public Function_1ffa60 {
  public:
    Method1(const char* s, CTriggerVolumeManager* m) : Function_1ffa60(s, 1) {
        owner = m;
        b18 = getFlag(&gA);
        b10 = getFlag(&gB);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, float v, CTriggerVolumeManager* m);
    virtual void f();
    float val;
};
Closure1::Closure1(const char* s, float v, CTriggerVolumeManager* m) : Method1(s, m) {
    val = v;
}

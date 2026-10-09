int g_current = -1;
class Target {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(int);
 char pad[8]; int key;
 void run(int, char);
};
Target* g_obj;
void Target::run(int arg, char flag) {
 if (key != g_current) {
  if (g_obj) g_obj->v13();
  g_current = key;
  v12();
  g_obj = this;
 }
 if (flag) v14(arg);
}
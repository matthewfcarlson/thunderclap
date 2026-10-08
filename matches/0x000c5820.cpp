extern int g_table[];
struct ISoundManager { virtual void f0(); virtual void f1(int, int); };
struct CFESoundManager : ISoundManager { virtual void f2(int, int); };
void CFESoundManager::f2(int a, int index) { f1(a, g_table[index]); }

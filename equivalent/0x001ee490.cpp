// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001ee490
struct CSoundSimManager { void callback(const char *, const char *, const char *, const char *); };
struct Closure4_CS { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void *, const char **, void *); char padding[0x18]; void (CSoundSimManager::*method)(const char *, const char *, const char *, const char *); CSoundSimManager *object; };
void Closure4_CS::vfunc_2(void *unused, const char **args, void *unused2) { (object->*method)(args[0], args[1], args[2], args[3]); }

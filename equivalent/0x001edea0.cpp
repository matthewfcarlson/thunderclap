// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSoundSimManager,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001edea0
class CSoundSimManager { public: void placeholder(); };
class Method4 {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2(CSoundSimManager* manager, const char** arguments, void* unused);
 char padding[0x18];
 void (CSoundSimManager::*callback)(const char*, const char*, const char*, const char*);
};
void Method4::vfunc_2(CSoundSimManager* manager, const char** arguments, void* unused) {
 (manager->*callback)(arguments[0], arguments[1], arguments[2], arguments[3]);
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,char_*,char_*,char_*,char_*>::vfunc_2 @ 0x0009d040
class CCameraManager {
public:
    void method(char *, char *, char *, char *);
};
class Closure4 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, char **, void *);
    char pad[0x18];
    void (CCameraManager::*method)(char *, char *, char *, char *);
    CCameraManager *object;
};
void Closure4::vfunc_2(void *, char **args, void *) {
    (object->*method)(args[0], args[1], args[2], args[3]);
}

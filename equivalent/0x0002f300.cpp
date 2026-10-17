// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,const_char_*,math::Vector>::vfunc_2 @ 0x0002f300
struct Vector { float x, y, z; };
class CActorManager {
public:
    unsigned int FUN_0002f300(Vector value);
};
class Closure1 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Vector *value, unsigned int *result);
    char reserved[0x18];
    unsigned int (CActorManager::*method)(Vector);
    CActorManager *manager;
};
void Closure1::vfunc_2(void *unused, const Vector *value, unsigned int *result)
{
    unsigned int answer = (manager->*method)(*value);
    if (result) *result = answer;
}
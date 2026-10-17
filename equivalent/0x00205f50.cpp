// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CWorldStreamManager,int,int>::vfunc_2 @ 0x00205f50
class CWorldStreamManager {};

class Closure1_CWorldStreamManager_int_int {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, int* argument, int* result);
private:
    char padding[0x18];
    int (CWorldStreamManager::*method)(int);
    CWorldStreamManager* object;
};

void Closure1_CWorldStreamManager_int_int::vfunc_2(void* unused, int* argument, int* result)
{
    int value = (object->*method)(*argument);
    if (result)
        *result = value;
}

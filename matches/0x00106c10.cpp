struct CPatrolPathManager {
    bool FUN_00106c10(const char*, bool, int);
};
struct Arguments {
    const char* text;
    bool flag;
    char padding[3];
    int count;
};
struct Closure {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments* args, bool* result);
    char padding[24];
    bool (CPatrolPathManager::*method)(const char*, bool, int);
    CPatrolPathManager* object;
};
void Closure::vfunc_2(int unused, Arguments* args, bool* result) {
    Arguments* a = args;
    CPatrolPathManager* obj = object;
    bool (CPatrolPathManager::*fn)(const char*, bool, int) = method;
    const char* text = a->text;
    bool flag = a->flag;
    int count = a->count;
    bool value = (obj->*fn)(text, flag, count);
    if (result)
        *result = value;
}
enum eMissionObjectiveState { dummy };
class CScenarioManager {
  public:
    int method(eMissionObjectiveState);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Closure1 : public Function {
  public:
    char pad[0x18];
    int (CScenarioManager::*method)(eMissionObjectiveState);
    CScenarioManager* object;
    virtual void vfunc_2(void*, eMissionObjectiveState*, int*);
};
void Closure1::vfunc_2(void*, eMissionObjectiveState* arg, int* out) {
    CScenarioManager* obj = object;
    int (CScenarioManager::*fn)(eMissionObjectiveState) = method;
    eMissionObjectiveState value = *arg;
    int result = (obj->*fn)(value);
    if (out)
        *out = result;
}

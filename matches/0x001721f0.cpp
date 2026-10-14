class Holder_1721f0 {
  public:
    int first();
    int second();
};
class SuckInPropsAction {
  public:
    char pad[0x20];
    Holder_1721f0* holder;
    bool vfunc_3(void*, void*);
};
bool SuckInPropsAction::vfunc_3(void*, void*) {
    int value = holder->first();
    if (value == 0)
        return false;
    if (((Holder_1721f0*)value)->second() == 0)
        return false;
    return true;
}
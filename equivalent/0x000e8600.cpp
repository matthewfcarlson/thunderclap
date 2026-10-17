// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e8600 @ 0x000e8600
extern float DAT_0040cc38;
struct Source {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7();
};
struct Evaluator { float FUN_000dfbf0(int); };
struct Entry { float factor; char unused[12]; };
struct Target {
    Evaluator** functions;
    char unused[4];
    Entry entries[8];
    int selected;
    float FUN_000e8600(int parameter, int index);
};
float Target::FUN_000e8600(int parameter, int index) {
    Evaluator* evaluator = functions[9 + index];
    Entry* entry = &entries[selected];
    Source* source = (Source*)functions[9];
    float divisor = source->slot7();
    float ratio = DAT_0040cc38 / divisor;
    float value = evaluator->FUN_000dfbf0(parameter);
    return value * entry->factor * ratio;
}

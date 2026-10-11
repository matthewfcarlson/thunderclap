// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::pddiBaseContext::vfunc_104 @ 0x0031d380
namespace pure3d {
struct pddiBaseContext {
    char reserved[0xa4];
    float firstNumerator;
    float reservedA8;
    float secondNumerator;
    float reservedB0;
    float firstDenominator;
    float firstResult;
    char reservedBC[8];
    float thirdNumerator;
    float reservedC8;
    float secondDenominator;
    float secondResult;
    void vfunc_104();
};
void pddiBaseContext::vfunc_104() {
    if (firstDenominator > 0.0f)
        firstResult = (secondNumerator + firstNumerator) / firstDenominator;
    else
        firstResult = 0.0f;
    if (secondDenominator > 0.0f)
        secondResult = thirdNumerator / secondDenominator;
    else
        secondResult = 0.0f;
}
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0030d850 @ 0x0030d850
typedef unsigned int uint;
struct Range {
    uint low, lowValue, high, highValue, extra;
    void FUN_0030d850(uint first, uint firstValue, uint second, uint secondValue, uint last);
};
void Range::FUN_0030d850(uint first, uint firstValue, uint second, uint secondValue, uint last)
{
    if (first < second) {
        low = first;
        lowValue = firstValue;
        high = second;
        highValue = secondValue;
    } else {
        low = second;
        lowValue = secondValue;
        high = first;
        highValue = firstValue;
    }
    extra = last;
}
// STATUS: equivalent (tools/equiv.py level 3: 288 inputs, branch coverage 8/8)
// FUN_0008f0b0 @ 0x0008f0b0
void* __cdecl FUN_0008d6d0(int size);

class IntArray_8f0b0 {
public:
    int mA;
    int mOne;
    int mZero8;
    int mCount;
    int mZero10;
    int mB;
    int pad18;
    int pad1c;
    int* mData;
    IntArray_8f0b0(int count, int b, int a);
};

IntArray_8f0b0::IntArray_8f0b0(int count, int b, int a)
{
    mCount = count;
    mB = b;
    mA = a;
    mOne = 1;
    mZero8 = 0;
    mZero10 = 0;
    mData = (int*)FUN_0008d6d0(count * 4);
    for (int i = 0; i < count; i++)
        mData[i] = 0;
}

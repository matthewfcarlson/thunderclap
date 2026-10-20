// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00299680 @ 0x00299680
// pure3d::CompositeDrawable::ActiveControllerList constructor: three arrays sized by a byte count.
void* __cdecl FUN_0008d6d0(unsigned int size);

namespace pure3d {
class CompositeDrawable {
public:
    class ActiveControllerList {
    public:
        virtual void v0();
        int refCount;
        char flag;
        char pad9[3];
        char* firstBegin;
        char* firstEnd;
        char pad14[4];
        char* secondBegin;
        char* secondEnd;
        char pad20[4];
        int* thirdBegin;
        int* thirdEnd;

        ActiveControllerList(unsigned char count);
    };
};
}

pure3d::CompositeDrawable::ActiveControllerList::ActiveControllerList(unsigned char count)
{
    refCount = 0;
    flag = 0;

    if (count > 0) {
        firstBegin = (char*)FUN_0008d6d0(count);
        if (firstBegin) {
            firstEnd = firstBegin + count;
        } else {
            firstBegin = 0;
            firstEnd = 0;
        }
    } else {
        firstBegin = 0;
        firstEnd = 0;
    }

    if (count > 0) {
        secondBegin = (char*)FUN_0008d6d0(count);
        if (secondBegin) {
            secondEnd = secondBegin + count;
        } else {
            secondBegin = 0;
            secondEnd = 0;
        }
    } else {
        secondBegin = 0;
        secondEnd = 0;
    }

    if (count > 0) {
        thirdBegin = (int*)FUN_0008d6d0(count * 4);
        if (thirdBegin) {
            thirdEnd = thirdBegin + count;
            return;
        }
    }
    thirdBegin = 0;
    thirdEnd = 0;
}

// STATUS: equivalent (tools/equiv.py level 3: 2642 inputs, branch coverage 4/4)
// FUN_00013420 @ 0x00013420
struct Item;
typedef void (__fastcall *ItemCallback)(Item *);
void __stdcall FUN_00013420(Item *items, int stride, int count, ItemCallback callback)
{
    char *end = (char *)items + stride * count;
    for (int i = 0; i < count; ++i) {
        end -= stride;
        callback((Item *)end);
    }
}
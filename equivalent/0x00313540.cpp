// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 27/28, incomplete)
// FUN_00313540 @ 0x00313540
struct Order { int largest; int middle; int smallest; };
extern "C" void __stdcall FUN_00313540(void * out, float a, float b, float c)
{
    if (a == b && a == c) {
        ((Order *)out)->largest = 0;
        ((Order *)out)->middle = 1;
        ((Order *)out)->smallest = 2;
        return;
    }
    int largest;
    if (a >= b && a >= c) largest = 0;
    else if (b >= c && b >= a) largest = 1;
    else largest = 2;
    ((Order *)out)->largest = largest;
    int smallest;
    if (a < b && a < c) smallest = 0;
    else if (b < c && b < a) smallest = 1;
    else smallest = 2;
    ((Order *)out)->smallest = smallest;
    if (largest != 0 && smallest != 0) ((Order *)out)->middle = 0;
    else if (largest != 1 && smallest != 1) ((Order *)out)->middle = 1;
    else ((Order *)out)->middle = 2;
}

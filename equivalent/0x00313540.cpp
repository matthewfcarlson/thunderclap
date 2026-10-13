// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 27/28, incomplete)
// FUN_00313540 @ 0x00313540
struct Order { int largest; int middle; int smallest; };
void __stdcall FUN_00313540(Order* out, float a, float b, float c)
{
    if (a == b && a == c) {
        out->largest = 0;
        out->middle = 1;
        out->smallest = 2;
        return;
    }
    int largest;
    if (a >= b && a >= c) largest = 0;
    else if (b >= c && b >= a) largest = 1;
    else largest = 2;
    out->largest = largest;
    int smallest;
    if (a < b && a < c) smallest = 0;
    else if (b < c && b < a) smallest = 1;
    else smallest = 2;
    out->smallest = smallest;
    if (largest != 0 && smallest != 0) out->middle = 0;
    else if (largest != 1 && smallest != 1) out->middle = 1;
    else out->middle = 2;
}

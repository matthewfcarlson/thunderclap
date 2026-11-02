// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0021c440 @ 0x0021c440
struct Input { char pad[0x1c]; int value; };
struct Output { int kind; int result; int unused; int start; int end; };
int __cdecl FUN_002209b0(int value, int extra);
// equiv-conv: FUN_0021c440 ecx eax esi
extern "C" void FUN_0021c440(void * input, int extra, void * output)
{
    int result = FUN_002209b0(((Input *)input)->value, extra);
    ((Output *)output)->start = -1;
    ((Output *)output)->end = -1;
    ((Output *)output)->kind = 4;
    ((Output *)output)->result = result;
}

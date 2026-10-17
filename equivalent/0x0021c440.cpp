// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0021c440 @ 0x0021c440
struct Input { char pad[0x1c]; int value; };
struct Output { int kind; int result; int unused; int start; int end; };
int __cdecl FUN_002209b0(int value, int extra);
// equiv-conv: FUN_0021c440 ecx eax esi
void FUN_0021c440(Input* input, int extra, Output* output)
{
    int result = FUN_002209b0(input->value, extra);
    output->start = -1;
    output->end = -1;
    output->kind = 4;
    output->result = result;
}

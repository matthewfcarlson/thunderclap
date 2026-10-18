// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00220a10 @ 0x00220a10
// FUN_00220a10 @ 0x00220a10
struct Request { int command; int value; int result; };
struct Source { int unused; int value; };
// equiv-conv: FUN_002208e0 ecx stack
int FUN_002208e0(Request*, int*);
// equiv-conv: FUN_00220a10 eax
int FUN_00220a10(Source* source) {
    Request request;
    request.command = 5;
    request.value = source->value;
    request.result = 0;
    return FUN_002208e0(&request, &request.result);
}

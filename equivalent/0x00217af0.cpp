// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00217af0 @ 0x00217af0
struct Pair_217af0 { int first, second; };
struct Record_217af0 { int type, value; Pair_217af0 left, right; };
struct Context { char pad[8]; Record_217af0 *out; };
Record_217af0 *__cdecl FUN_002175b0(Context *, Pair_217af0 *, int);
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(Context *, int);
// equiv-conv: FUN_00217af0 esi ebx edi stack stack
int FUN_00217af0(Context *self, Pair_217af0 *left, Pair_217af0 *right, int arg1, int arg2)
{
    Record_217af0 *r = FUN_002175b0(self, left, arg2);
    if (r->type == 0) r = FUN_002175b0(self, right, arg2);
    if (r->type != 6) return 0;
    Record_217af0 *out = self->out;
    out->type = 6;
    out->value = r->value;
    out = self->out;
    out->left.first = left->first;
    out->left.second = left->second;
    out = self->out;
    out->right.first = right->first;
    out->right.second = right->second;
    FUN_00217790(self, arg1);
    return 1;
}
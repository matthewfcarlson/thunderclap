// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0033c790 @ 0x0033c790
struct Capture { const char *text; unsigned length; };
struct Matcher { char pad[4]; const char *end; void *context; int count; Capture captures[1]; };
int __cdecl FUN_00338e20(void *, const char *);
// equiv-conv: FUN_0033c790 eax ecx ebx
const char *FUN_0033c790(int index, Matcher *self, const char *position)
{
    index -= 0x31;
    if (index < 0 || index >= self->count || self->captures[index].length == 0xffffffffu)
        index = FUN_00338e20(self->context, "invalid capture index");
    unsigned length = self->captures[index].length;
    if ((unsigned)(self->end - position) >= length) {
        const char *text = self->captures[index].text;
        for (unsigned i = 0; i < length; ++i)
            if (text[i] != position[i]) return 0;
        return position + length;
    }
    return 0;
}
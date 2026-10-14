// STATUS: equivalent (tools/equiv.py level 3: 712 inputs, branch coverage 12/12)
// FUN_00261e60 @ 0x00261e60
struct Writer_261e60 {
    char pad00[0x24];
    int depth;
};

struct Output_261e60 {
    Writer_261e60 *writer;
};

char __cdecl FUN_00246f50(Writer_261e60 *w, const char *fmt, ...);

struct Link_261e60 {
    Link_261e60 *next;
};

struct Elem_261e60 {
    float value;
    Link_261e60 link;
};

static Elem_261e60 *ElemOf(Link_261e60 *l)
{
    return l ? (Elem_261e60 *)((char *)l - 4) : 0;
}

class FloatList {
public:
    Link_261e60 *head;
    bool FUN_00261e60(Output_261e60 *out);
};

// Writes "[\n", one "%f\n" line per element, then "]\n".
bool FloatList::FUN_00261e60(Output_261e60 *out)
{
    if (!FUN_00246f50(out->writer, "[\n"))
        return false;
    out->writer->depth++;
    for (Elem_261e60 *e = ElemOf(head); e; e = ElemOf(e->link.next)) {
        if (!FUN_00246f50(out->writer, "%f\n", (double)e->value))
            return false;
    }
    out->writer->depth--;
    return FUN_00246f50(out->writer, "]\n") != 0;
}

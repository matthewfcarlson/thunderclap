// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 0/0)
// FUN_00213360 @ 0x00213360
struct CommandBuffer { char pad[8]; char *cursor; };
void __cdecl FUN_00213360(CommandBuffer *buffer, int value)
{
    struct Entry { int type; float value; };
    Entry *entry = (Entry *)buffer->cursor;
    entry->type = 3;
    entry->value = (float)value;
    buffer->cursor += 8;
}

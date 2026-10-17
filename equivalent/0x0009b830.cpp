// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_0009b830 @ 0x0009b830
struct Callback {
    unsigned char invoke(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
struct Data {
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
    unsigned char tag;
};
void __cdecl FUN_0009b830(Callback* object, Data* data, unsigned char* result, unsigned char (Callback::*callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))
{
    unsigned int first = data->first;
    unsigned int second = data->second;
    unsigned int third = data->third;
    unsigned int fourth = data->fourth;
    unsigned char tag = data->tag;
    unsigned int taggedPointer = (reinterpret_cast<unsigned int>(data) & 0xffffff00U) | tag;
    unsigned char value = (object->*callback)(first, second, third, fourth, taggedPointer);
    if (result) *result = value;
}
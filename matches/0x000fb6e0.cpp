typedef unsigned int uint;
bool compare(const short *a, const short *b, uint count)
{
    uint i=0;
    while (i < count) {
        if (*a != *b) return false;
        ++a; ++b; ++i;
    }
    return true;
}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_00267b10 @ 0x00267b10
extern int DAT_004cd5ac[];   // days before each month (non-leap), indexed by month

// Day of the week (0..6) for a Gregorian date.
unsigned int __cdecl FUN_00267b10(unsigned short year, unsigned char month, unsigned char day)
{
    bool leap = false;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        leap = true;

    unsigned int dayOfYear = DAT_004cd5ac[month] + day - 1;
    if (leap && month > 2)
        dayOfYear++;

    int y = (year - 1) % 400;
    unsigned int uy = (unsigned int)y;
    unsigned int centuryAdjust = (uy >> 2) - uy / 100 + uy;
    return (centuryAdjust % 7 + dayOfYear) % 7;
}

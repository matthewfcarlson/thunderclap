#!/usr/bin/env python3
"""Map the platform boundary: every call from game code into XDK / kernel / CRT / Bink.

  build/venv/bin/python tools/platform_map.py            # writes build/port/platform_calls.json
  build/venv/bin/python tools/platform_map.py --summary  # plus a text summary on stdout

Inputs:
  build/port/refs.tsv   from tools/ghidra_scripts/ExportRefs.java (body ranges + references)
  build/functions.csv   names (XbSymbolDatabase names for XDK code)
  build/xbsymbols.txt   XbSymbolDatabase data symbols (D3D__g_RenderState, ...)
  build/rtti.json       classes and vtables (seam classes)
  default.xbe           kernel thunk table, raw bytes for the MMIO / port-I/O scan
  the ghidra-xbe extension jar: xboxkrnl export names by ordinal (parsed, not copied)

"Game code" is .text below 0x364840 minus the two library spans linked into it:
XAPILIB (0x208b9c-0x212bb0) and LIBCMT + XAPI tail (0x3440e0-0x356bf0, 0x35a7b0-0x35be88). Everything after
.text (BINK*, D3D, XGRPH, DSOUND, XPP) is library. See docs/platform-boundary.md.
"""
import argparse
import collections
import csv
import json
import os
import re
import struct
import sys
import zipfile

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
B = lambda *p: os.path.join(ROOT, "build", *p)
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
JAR = B("tools/ghidra_12.0.3_PUBLIC/Ghidra/Extensions/ghidra-xbe/lib/ghidra-xbe.jar")

GAME_TEXT_END = 0x364840
LIB_SPANS = [  # (start, end, label) library code linked inside .text
    (0x208b9c, 0x212bb0, "XAPI"),   # XAPILIB (+ xboxkrnl jmp stubs at the end)
    (0x3440e0, 0x356bf0, "CRT"),    # LIBCMT + more XAPILIB (/O1 /Oy-, unaligned)
    (0x35a7b0, 0x35be88, "CRT"),    # LIBCMT EH runtime, itoa, 64-bit helpers
]
# 0x356bf0-0x35a7b0 is aligned /O2 game math/collision code linked after the CRT, and
# 0x35be88-0x364840 is .text$yc/.text$yd (game dynamic initializers / atexit thunks): game.
KERNEL_DATA = {"KeTickCount", "LaunchDataPage", "XboxHardwareInfo", "XboxKrnlVersion", "XboxHDKey",
               "XboxSignatureKey", "XboxAlternateSignatureKeys", "XeImageFileName", "KeTimeIncrement",
               "HalDiskCachePartitionCount", "IdexChannelObject", "PsThreadObjectType", "ExEventObjectType",
               "ExSemaphoreObjectType", "ExMutantObjectType", "ExTimerObjectType", "IoFileObjectType"}
# Library functions XbSymbolDatabase / Ghidra FID left unnamed (or misnamed) that game code calls.
# Identified by hand from their kernel imports, constants and strings; see docs/platform-boundary.md.
IDENTIFIED = {
    0x344e74: "__RTDynamicCast",           # 5 args (ptr, vfdelta, src, target, isRef); throws bad_cast
    0x34483c: "_ftol",                     # fistp qword, x87 control word
    0x345880: "_chkstk",                   # page-probing stack allocation (eax = size)
    0x3458c1: "atof",                      # __ld12tod
    0x345804: "sscanf",                    # _input: ungetc, __hextodec, __inc
    0x346672: "_CIpow",                    # 2-arg x87 helper (__fpclass, __frnd, error handling)
    0x34777a: "_CIfmod",                   # fprem loop
    0x345b90: "toupper",                   # _isctype(c, _LOWER) under __mb_cur_max
    0x345475: "tolower",                   # _isctype(c, _UPPER)
    0x344913: "type_info::operator==",     # compares decorated names at +9
    0x3473c6: "strcmp",
    0x3449e4: "__RTtypeid",                # "Attempted a typeid of NULL pointer!"
    0x3479bc: "free",                      # heap lock, NtFreeVirtualMemory
    0x3465c6: "_nh_malloc",                # NtAllocateVirtualMemory + _callnewh
    0x347aa0: "calloc",                    # n*size, zeroing
    0x347b53: "strerror",                  # _getptd()->_errmsg (134-byte buffer)
    0x347ba4: "_errno",                    # _getptd()+8
    0x347eed: "puts",
    0x345d81: "_exit",
    0x3465b3: "fopen",                     # _fsopen(name, mode, _SH_DENYNO)
    0x3471a3: "_fcloseall",
    0x3472cb: "strtod",
    0x348010: "_CIexp",                    # matherr path
    0x348380: "_strupr",
    0x356734: "sprintf (vsprintf wrapper)",
    0x3441f0: "_CIsqrt-class 1-arg x87 helper",
    0x3442bc: "_CIlog-class 1-arg x87 helper",
    0x3469f5: "type_info::name (undname)",
    0x20bbc2: "CloseHandle",               # NtClose
    0x2101d4: "SetFilePointer",            # NtQuery/SetInformationFile(FilePositionInformation)
    0x2109b6: "GetFileSize",               # NtQueryInformationFile(FileStandardInformation)
    0x210150: "SetEndOfFile",              # FilePosition query + FileEndOfFileInformation
    0x21007a: "WriteFile",                 # NtWriteFile + wait
    0x20ff8d: "ReadFile",                  # NtReadFile + wait
    0x2109f1: "CreateFileA",               # NtCreateFile
    0x209a8e: "GetDiskFreeSpaceExA",       # NtQueryVolumeInformationFile
    0x208b9c: "GetDiskFreeSpaceExA (MU)",  # same pattern, second copy
    0x2120f5: "XCalculateSignatureUpdate", # XcSHAUpdate
    0x212143: "XCalculateSignatureEnd",    # XcSHAFinal/XcHMAC
    0x20c14b: "GetCurrentThreadId",        # fs:[0x28] -> thread
    0x209f01: "GlobalMemoryStatus",        # MmQueryStatistics
    0x20c6f7: "WaitForSingleObject",       # NtWaitForSingleObjectEx(alertable=0)
    0x20c723: "Sleep",                     # KeDelayExecutionThread
    0x20c2c9: "CreateSemaphoreA",          # NtCreateSemaphore
    0x20c380: "ReleaseSemaphore",          # NtReleaseSemaphore
    0x20bd91: "ResumeThread",              # NtResumeThread
    0x20c731: "HeapCreate",                # RtlCreateHeap flags
    0x20e1a1: "HeapAlloc",                 # RtlAllocateHeap
    0x20c79c: "HeapFree",                  # RtlFreeHeap
    0x20d7ff: "HeapSize",                  # heap entry header read
    0x21257d: "XapiOpenDirectory (NtOpenFile dir)",
    0x209f50: "XGetLanguage",              # ExQueryNonVolatileSetting(7 = XC_LANGUAGE)
    0x356667: "XGetVideoFlags",            # ExQueryNonVolatileSetting(8 = XC_VIDEO_FLAGS) >> 16 & 0x5f
    0x354c8f: "XGetAudioFlags",            # ExQueryNonVolatileSetting(9 = XC_AUDIO_FLAGS)
    0x356a02: "XGetAVPack",
    0x355364: "GetLocalTime",              # KeQuerySystemTime + time zone + RtlTimeToTimeFields
    0x35618d: "XCreateSaveGame",           # "\SaveMeta.xbx", swprintf, KeQuerySystemTime
    0x3563f0: "XDeleteSaveGame / XFindFirstSaveGame",  # "\??\" UDATA path walk
    0x356611: "XFindClose",                # closes the handle kinds tagged 'TNOC'/'KCIN'
    0x355791: "XFindNextSoundtrack",       # custom soundtracks (TDATA\FFFE0000\MUSIC)
    0x3559b9: "XOpenSoundtrackSong",       # "%s%04x\%08x.WMA"
    0x355ab5: "XFindFirstSoundtrack",
    0x355bc2: "XFindNextSoundtrack (dir)",
    0x355c13: "XapiSoundtrack create",
    0x355c7f: "XapiSoundtrack set-info",
    0x3564c0: "XFindFirstSaveGame",
    0x3565ca: "XFindNextSaveGame",
    0x354ce2: "QueryPerformanceFrequency",  # constant 0x2bb5c755 = 733,333,333 Hz
    0x37d8e0: "D3D_SetPushBufferSize",     # stores two globals; XbSymbolDatabase put this name on 0x244c0
    0x37d240: "Direct3D_AddRef/Release stub",
    0x382400: "D3DDevice_CreateImageSurface/RenderTarget",
    0x38acb0: "D3D GetSurfaceDesc helper",
    0x3a04fc: "XGBuffer_GetBufferPointer",
    0x3a41dc: "XGBuffer_Release",
    0x3a8753: "XGAssembleShader",          # 11-arg wrapper, error-buffer printf
}
MMIO_RANGES = [(0xFD000000, 0xFE000000, "NV2A MMIO"), (0xFE800000, 0xFE880000, "APU MMIO"),
               (0xFE830000, 0xFE840000, "APU VP"), (0xFEC00000, 0xFEC01000, "ACI"),
               (0xFED00000, 0xFED01000, "USB0"), (0xFEF00000, 0xFF000000, "NIC/other MMIO")]
# (0xF0000000-0xF7FFFFFF, the AGP/framebuffer aperture, only produced false positives: masks and hashes.)


# ---------------------------------------------------------------------------------------------
# Inputs

def kernel_names():
    """xboxkrnl export names indexed by ordinal-1, read from the ghidra-xbe loader's constant pool."""
    d = zipfile.ZipFile(JAR).read("xbeloader/XbeLoader.class")
    n, = struct.unpack_from(">H", d, 8)
    o, i, utf = 10, 1, []
    while i < n:
        t = d[o]
        if t == 1:
            l, = struct.unpack_from(">H", d, o + 1)
            utf.append(d[o + 3:o + 3 + l].decode("utf8", "replace"))
            o += 3 + l
        elif t in (3, 4, 9, 10, 11, 12, 17, 18):
            o += 5
        elif t in (5, 6):
            o += 9
            i += 1
        elif t in (7, 8, 16, 19, 20):
            o += 3
        elif t == 15:
            o += 4
        else:
            raise ValueError("bad constant pool tag %d" % t)
        i += 1
    a = utf.index("AvGetSavedDataAddress")
    return utf[a:a + 366]


class Image:
    def __init__(self):
        self.xbe = Xbe(XBE_PATH)
        self.funcs = {}        # entry -> dict(name, ranges, size)
        self.refs = collections.defaultdict(list)       # entry -> [(insn, target, type)]
        self.indirect = collections.defaultdict(list)   # entry -> [(insn, text)]
        with open(B("port/refs.tsv")) as f:
            for line in f:
                p = line.rstrip("\n").split("\t")
                if p[0] == "F":
                    rs = [tuple(int(x, 16) for x in r.split("-")) for r in p[3].split(",") if r]
                    self.funcs[int(p[1], 16)] = {"name": p[2], "ranges": rs}
                elif p[0] == "R":
                    self.refs[int(p[1], 16)].append((int(p[2], 16), int(p[3], 16), p[4]))
                elif p[0] == "C":
                    self.indirect[int(p[1], 16)].append((int(p[2], 16), p[3]))
        self.thunk = {}
        with open(B("functions.csv")) as f:
            for r in csv.DictReader(f):
                va = int(r["address"], 16)
                if va in self.funcs:
                    self.funcs[va]["size"] = int(r["size"])
                    self.funcs[va]["is_thunk"] = r["is_thunk"] == "1"
        self.sym = {}  # XbSymbolDatabase symbols (functions and data)
        if os.path.exists(B("xbsymbols.txt")):
            for line in open(B("xbsymbols.txt")):
                m = re.match(r"(\w+?)__(\w+) = 0x([0-9a-f]+)", line.strip())
                if m:
                    self.sym[int(m.group(3), 16)] = "%s::%s" % (m.group(1), m.group(2))
        # Kernel thunk table.
        d = self.xbe.data
        kt, = struct.unpack_from("<I", d, 0x158)
        self.kthunk_va = kt ^ 0x5B6D40B6
        kn = kernel_names()
        self.kthunk = {}
        o = self.xbe.offset(self.kthunk_va)
        va = self.kthunk_va
        while True:
            v, = struct.unpack_from("<I", d, o)
            if v == 0:
                break
            ordn = v & 0x7FFFFFFF
            self.kthunk[va] = (ordn, kn[ordn - 1])
            o += 4
            va += 4
        self.sorted_entries = sorted(self.funcs)
        rtti = json.load(open(B("rtti.json")))
        self.vftables = {}
        self.slot_owner = collections.defaultdict(list)
        for c in rtti["classes"]:
            if not c["name"]:
                continue
            for v in c["vtables"]:
                self.vftables[v["address"]] = (c["name"], v["offset"], len(v["slots"]))
                for i, fva in enumerate(v["slots"]):
                    self.slot_owner[fva].append((c["name"], i))
        self.classes = {c["name"]: c for c in rtti["classes"] if c["name"]}

    # -- classification -----------------------------------------------------------------------
    def region(self, va):
        if 0x11000 <= va < GAME_TEXT_END:
            for a, b, label in LIB_SPANS:
                if a <= va < b:
                    return label
            return "game"
        if va in self.kthunk:
            return "kernel"
        s = self.xbe.section_of(va)
        if s is None:
            return None
        if s.name.startswith("BINK"):
            return "BINK"
        return s.name  # D3D, XGRPH, DSOUND, XPP, .rdata, .data, DOLBY, ...

    def is_game_func(self, va):
        return self.region(va) == "game"

    def name(self, va):
        f = self.funcs.get(va)
        n = f["name"] if f else None
        if va in self.sym and (n is None or n.startswith("FUN_") or n.startswith("DAT_")):
            n = self.sym[va]
        return n

    def insns(self, va, n=4):
        o = self.xbe.offset(va)
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        md.detail = True
        return list(md.disasm(self.xbe.data[o:o + 16 * n], va))[:n]

    def resolve(self, va, depth=0):
        """Follow jmp-thunks (jmp imm / jmp [kernel thunk]) to the real target."""
        if depth > 8:
            return ("func", va)
        if va in self.kthunk:
            return ("kernel", va)
        f = self.funcs.get(va)
        ins = self.insns(va, 1)
        if ins and ins[0].mnemonic == "jmp":
            op = ins[0].operands[0]
            if op.type == capstone.x86.X86_OP_IMM:
                return self.resolve(op.imm, depth + 1)
            if op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                if op.mem.disp in self.kthunk:
                    return ("kernel", op.mem.disp)
        return ("func", va)

    def target_key(self, kind, va):
        """(key, region, display name) for a resolved platform target."""
        if kind == "kernel":
            ordn, kname = self.kthunk[va]
            return ("xboxkrnl!%s" % kname, "kernel", kname)
        reg = self.region(va)
        if va in IDENTIFIED:
            return (IDENTIFIED[va], reg, IDENTIFIED[va])
        n = self.name(va) or "FUN_%08x" % va
        n = re.sub(r"^(XAPILIB|xboxkrnl\.exe)::", "", n)
        n = re.sub(r"^(D3D8|DSOUND|XGRAPHC)::", "", n)
        if n.startswith("FUN_") or n.startswith("thunk_FUN"):
            n = "%s!%s" % (reg, n)
        return (n, reg, n)


# ---------------------------------------------------------------------------------------------
# Subsystem classification of platform functions

SUBSYS_RULES = [
    ("C++ runtime", r"^operator new|type_info|__RTDynamicCast|__RTtypeid|__security_check_cookie|^_atexit|^_chkstk|setjmp|longjmp|^_?_?purecall|_onexit|^_errno|^strerror|^_exit|^_fcloseall"),
    ("CRT: heap/stdio", r"^_?malloc$|^free$|^calloc$|^_nh_malloc$|^fopen$|^_fclose$|_fwprintf$|_getc$|^_?_?fflush$|^_?realloc$"),
    ("movies", r"^BINK|Bink"),
    ("graphics", r"^Direct3D|^D3D|^XGRPH|D3D|^CMiniport|^CDevice|^XG(?!et)[A-Z]|Surface|^Av[GS]|AvSendTV|^MmClaimGpu|^MmPersistContiguous|HalBootSMCVideoMode|^Lock|PushBuffer"),
    ("audio", r"Soundtrack|^DSOUND|DirectSound|^CDirectSound|^CMcpx|^XAudio|^XFile.*Media|^WaveFormat|^CAc97|^Dolby"),
    ("input", r"^XInput|^XGetDevice|^XInitDevices|^XID_|^XPP|^XapiInitDevices|^IUsb|Usb"),
    ("saves/storage", r"SaveGame|^XMU|^XMount|^XUnmountMU|^XReadMUMetaData|Signature|^XcSHA|^XcHMAC|SoundtrackS|^XFindFirstSave|^XGetDisplayBlocks|XboxHDKey|XboxSignatureKey|^XCreateSaveGame|^XDeleteSaveGame|^XFindNextSave|^XFindClose|Utility|AlternateTitle|Formatut|CachePartition"),
    ("networking/live", r"^XNet|^XOnline|^Xon|^socket|^recv|^send|^WSA|^XNetStartup"),
    ("file I/O", r"File|^Nt(Close|Open|Read|Write|Query.*File|SetInformationFile|Fs|DeviceIoControl|Flush|QueryVolume|QueryDirectory|QueryFullAttr)|^Io|Directory|^CloseHandle|^XapiMapLetter|^GetDiskFree|SymbolicLink|^Fsc|DriveLetter|^__sopen|^_?_?fopen|^_?f(read|write|close|seek|tell|flush|open|getc|putc|gets|puts|printf|scanf)|^__lock_fhandle|osfhnd|osfhandle|^__flsbuf|^__flswbuf|^__setmode|^_?_?read|^_?_?write|^_?_?lseek|^_?_?close|^__isatty|IoCompletion|GetOverlappedResult"),
    ("threads/sync", r"Thread|Fiber|Event|Mutex|Mutant|Semaphore|Wait|CriticalSection|^Sleep|APC|Apc|Object|^SwitchTo|Irql|Dpc|Interrupt|Priority|^SignalObjectAndWait|^NtYieldExecution|^XSetProcessQuantum|^KeStall|^_?_?lock|^_?_?unlock|^_?_?mtinit|^XRegisterThreadNotify|^Ps|^Ke(Set|Insert|Remove|Synchronize)|^Ob|Tls|^XapiThread|Interlocked"),
    ("timing", r"PerformanceCounter|PerformanceFrequency|QuerySystemTime|TickCount|InterruptTime|^KeQuery|Time|Timer|^XAutoPowerDown|^rdtsc|^_?_?time|^_?_?clock|^_?_?ftime"),
    ("memory", r"MemoryStatus|Alloc|Free|^Mm|Heap|Virtual|^_?_?malloc|^_?_?calloc|^_?_?realloc|^_?_?free|^_?_?msize|Pool|^XMem|^XPhysical|^_?_?sbh|AddressProtect|KernelStack|^_?_?nh_malloc|^_?_?heap"),
    ("process/system", r"^XLaunch|^XGetLaunchInfo|^Xapi(BootToDash|InitProcess|SelectCache|SetLastNT|Format)|^HalReturnToFirmware|^HalInitiateShutdown|^HalRegisterShutdown|^HalIsReset|Shutdown|^XGet(Language|VideoFlags|AVPack|GameRegion|ParentalControl|AudioFlags|TimeZone|LocalTime)|^GetTimeZone|^ExQueryNonVolatileSetting|^XGetSection|^XLoadSection|^XFreeSection|^Xe(Load|Unload)Section|^XeImageFileName|^XboxHardwareInfo|^XboxKrnlVersion|^LaunchDataPage|^entry|^mainCRT|^mainXapi|^_?_?cinit|^_?_?rtinit|^_?_?exit|^_?_?amsg_exit|^_?_?initterm|^XGetSectionSize|^GetLastError|^SetLastError|^RtlNtStatusToDosError|^XapiSetLastNTError|^XGetDisplay|^XQueryValue|^XSetValue|^XGetFileCacheSize|^XSetFileCacheSize|^XapiFormatObjectAttributes"),
    ("debug/exceptions", r"^Dbg|OutputDebugString|^KeBugCheck|Exception|Unwind|^__?CxxFrameHandler|^_?_?CxxThrow|^__?purecall|^_?_?assert|^_?RTC|^_?_?security|EH|Catch|Frame|^_CallMember|^_JumpTo|^__?SEH|^_?_?except|^_?_?local_unwind|^_?_?global_unwind|^_?_?abnormal|^_?_?inconsistency|^terminate|^unexpected|^_?_?CallSettingFrame|^\?|^_?_?FrameUnwind|^_?_?DestructExceptionObject|^__?ArrayUnwind|^FID_conflict"),
    ("CRT: string/memory", r"^_?_?(qsort|bsearch|ungetc|is[a-z]+$|mem|str|wcs|_?mbs|tolower|toupper|isalpha|isdigit|isspace|isalnum|iswctype|_?towlower|_?towupper|_?isctype|wcslen|strtok|stricmp|strnicmp|_?strlwr|_?strupr|_?wcsicmp|_?wcsnicmp|_?strdup|_?wcsdup)|^RtlInitAnsiString|^RtlCompare|^RtlEqualString|^RtlFill"),
    ("CRT: formatting", r"^puts|printf|scanf|^_?_?(itoa|ltoa|ultoa|i64toa|ui64toa|xtoa|atoi|atol|atof|strtol|strtoul|strtod|_?ecvt|_?fcvt|_?gcvt|cfltcvt|cftoe|cftof|cftog|fassign|_?output|_?input|wtoi|wtol|_?wcstol)|^Rtl.*printf|^_?x64toa|^@x64toa"),
    ("CRT: math", r"_CI|^_?_?(aulldvrm|ftol|ftol2|CI|ci|allmul|alldiv|allrem|aulldiv|aullrem|allshl|allshr|aullshr|sqrt|sin|cos|tan|atan|atan2|asin|acos|pow|exp|log|log10|fmod|floor|ceil|fabs|frexp|ldexp|modf|hypot|control87|controlfp|clear87|status87|fpreset|fpmath|FPinit|_?trandisp|_?startOneArgErrorHandling|_?math_exit|_?87except|_?ctrlfp|_?fload|_?frnd|addl|add_12|shl_12|shr_12|ld12|mtold12|fltin|strgtold|_?rand|srand|_?isnan|_?finite|_?copysign|_?chgsign|_?fpclass|_?nextafter|_?logb|_?scalb|abs|labs|div|ldiv)|^Ke(Save|Restore)FloatingPointState"),
]


def classify(name):
    base = re.sub(r"^(\w+!)", "", name)
    region = name.split("!")[0] if "!" in name else ""
    for sub, pat in SUBSYS_RULES:
        if re.search(pat, base) or (region and re.search(pat, region)):
            return sub
    return "misc"


# ---------------------------------------------------------------------------------------------
# Scan

# XDK D3D state the game touches directly through d3d8.h inline functions (SetRenderState,
# SetTextureStageState, ...). Bases from XbSymbolDatabase (D3D__g_DeferredTextureState,
# D3D__g_RenderState); D3D__DirtyFlags is inferred (the word OR-ed with dirty bits before
# D3DDevice_SetRenderState_* calls).
def d3d_data_name(va):
    if va == 0x39db08:
        return "D3D__DirtyFlags"
    if 0x39db10 <= va < 0x39dd10:
        o = (va - 0x39db10) // 4
        return "D3D__TextureState[%d][%d]" % (o // 32, o % 32)
    if 0x39dd10 <= va < 0x39dfa8:
        return "D3D__RenderState[%d]" % ((va - 0x39dd10) // 4)
    if va == 0x39dfa8:
        return "D3D__pDevice"
    return None


def scan(img):
    calls = collections.defaultdict(lambda: collections.Counter())   # target key -> Counter(caller)
    target_meta = {}
    data_refs = collections.defaultdict(lambda: collections.Counter())   # xdk data sym -> callers
    hw = []          # (caller, insn, what)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    game = [va for va in img.sorted_entries if img.is_game_func(va)]
    for va in game:
        f = img.funcs[va]
        for insn, tgt, rtype in img.refs.get(va, ()):
            if "CALL" in rtype or "JUMP" in rtype:
                kind, real = img.resolve(tgt)
                reg = "kernel" if kind == "kernel" else img.region(real)
                if reg in (None, "game", ".rdata", ".data"):
                    continue
                key, reg, disp = img.target_key(kind, real)
                calls[key][va] += 1
                target_meta[key] = {"region": reg, "address": "0x%x" % real, "jump": "JUMP" in rtype}
            else:
                reg = img.region(tgt)
                if reg == "kernel":
                    ordn, kname = img.kthunk[tgt]
                    if kname in KERNEL_DATA:
                        key = "xboxkrnl!%s" % kname
                        calls[key][va] += 1
                        target_meta[key] = {"region": "kernel", "address": "0x%x" % tgt, "data": True}
                    continue  # code-pointer reads of the thunk table are covered by indirect calls
                if reg in ("DOLBY", "BINKDATA") and rtype == "DATA":
                    continue  # immediates that happen to land there (FourCCs like 'TEX' = 0x584554)
                if reg in ("D3D", "XGRPH", "DSOUND", "XPP", "BINK", "XAPI", "CRT", "DOLBY", "BINKDATA"):
                    kind, real = img.resolve(tgt) if tgt in img.funcs else ("data", tgt)
                    if kind == "func" and real in img.funcs and img.region(real) not in (None, ".rdata", ".data"):
                        # address-of a library function (callback / function pointer)
                        key, reg2, disp = img.target_key(kind, real)
                        calls[key][va] += 1
                        target_meta.setdefault(key, {"region": reg2, "address": "0x%x" % real, "addr_taken": True})
                        continue
                    key = d3d_data_name(tgt) or (img.sym[tgt].split("::", 1)[1] if tgt in img.sym else "%s!DAT_%08x" % (reg, tgt))
                    data_refs[key][va] += 1
        for insn, text in img.indirect.get(va, ()):
            m = re.match(r"(CALL|JMP) dword ptr \[0x([0-9a-f]+)\]$", text)
            if m:
                p = int(m.group(2), 16)
                if p in img.kthunk:
                    ordn, kname = img.kthunk[p]
                    key = "xboxkrnl!%s" % kname
                    calls[key][va] += 1
                    target_meta[key] = {"region": "kernel", "address": "0x%x" % p}
        # raw-byte scan for hardware access
        for a, b in f["ranges"]:
            o = img.xbe.offset(a)
            if o is None:
                continue
            for ins in md.disasm(img.xbe.data[o:o + (b - a + 1)], a):
                m = ins.mnemonic
                if m in ("in", "out", "ins", "outs", "insb", "insd", "outsb", "outsd", "rdtsc", "rdmsr", "wrmsr",
                         "cli", "sti", "wbinvd", "invd", "hlt", "cpuid", "rdpmc"):
                    hw.append((va, ins.address, m + " " + ins.op_str))
                    continue
                for op in ins.operands:
                    v = None
                    if op.type == capstone.x86.X86_OP_IMM:
                        v = op.imm & 0xFFFFFFFF
                    elif op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0:
                        v = op.mem.disp & 0xFFFFFFFF
                    if v is None:
                        continue
                    for lo, hi, what in MMIO_RANGES:
                        if lo <= v < hi:
                            hw.append((va, ins.address, "%s 0x%08x: %s %s" % (what, v, m, ins.op_str)))
    return calls, target_meta, data_refs, hw, game


# ---------------------------------------------------------------------------------------------
# Seams: translation-unit clustering of platform callers

def owner_class(img, va):
    """Class that owns a function: the vtable slot owner with the fewest bases, or by name."""
    own = img.slot_owner.get(va)
    if own:
        best = min(own, key=lambda t: len(img.classes[t[0]]["bases"]))
        return best[0]
    n = img.funcs[va]["name"]
    if "::" in n and not n.startswith(("FUN_", "thunk")):
        return n.rsplit("::", 1)[0]
    return None


def vtable_refs(img, va):
    """Classes whose vftable this function references (constructors / destructors)."""
    out = set()
    for insn, tgt, rtype in img.refs.get(va, ()):
        if tgt in img.vftables:
            out.add(img.vftables[tgt][0])
    return out


def neighbourhood_class(img, va, radius=12):
    """Guess the class of a non-virtual function from the classes around it (same TU)."""
    i = img.sorted_entries.index(va)
    votes = collections.Counter()
    for j in range(max(0, i - radius), min(len(img.sorted_entries), i + radius + 1)):
        e = img.sorted_entries[j]
        if not img.is_game_func(e):
            continue
        c = owner_class(img, e)
        w = 1.0 / (1 + abs(i - j))
        if c:
            votes[c] += w
        for c2 in vtable_refs(img, e):
            votes[c2] += 0.5 * w
    return votes.most_common(3)


# Engine seams. Pure3D/radcore/radsound keep each library's translation units together, so a seam
# is an address range (checked against the RTTI owners of the functions inside it).
SEAMS = [
    ("render", "pure3d pddi D3D8 backend (d3dDisplay/d3dDevice/d3dContext/d3dTexture/d3dPrimBuffer/d3d*Shader/d3dExt*)", [(0x31ac80, 0x3338e0)]),
    ("core-platform", "radcore Xbox layer: timers, controllers, memory, threads/fibers, debug console, drives/files/saves", [(0x267000, 0x27ab50)]),
    ("audio-hal", "radsound Xbox HAL: DirectSound device, voices/buffers, its heap", [(0x240c00, 0x241400), (0x258e00, 0x259c80)]),
    ("movie", "movie::PlayerBink / RenderStrategyBink / BinkCallback", [(0x3338e0, 0x335200)]),
]
# QoL subsystem functions found for docs/subsystems.md (address -> (label, subsystem)). Labels are
# names for Ghidra (applied by tools/ghidra_scripts/ApplyPortLabels.java); evidence is in the doc.
QOL = [
    # boot / main loop / frame timing
    (0x8ee30, "main", "loop"),
    (0x8fca0, "ReadArgsTxt", "boot"),
    (0x8f880, "ParseCommandLineSwitches", "boot"),
    (0x8d660, "PlatformEarlyInit", "boot"),
    (0x87e80, "CGame::CGame", "loop"),
    (0x88530, "CGame::Run", "loop"),
    (0x88020, "CGame::Init", "loop"),
    (0x879c0, "CGame::ShowCopyrightScreen3s", "boot"),
    (0x87940, "CGame::MainLoop", "loop"),
    (0x87630, "CGame::Tick", "loop"),
    (0x86cb0, "CGame::Render", "loop"),
    (0x873a0, "CGame::ApplyStateChange", "loop"),
    (0x86a40, "CGame::UpdateFrontEnd", "loop"),
    (0x88c30, "CGame::UpdateSimulation", "loop"),
    (0x86630, "CGame::EnterPreGame", "loop"),
    (0x86790, "CGame::EnterPressStart", "loop"),
    (0x86900, "CGame::LeavePressStart", "loop"),
    (0x8db00, "PumpPlatformServices", "loop"),
    (0x8db60, "SetFrontEndVSync60", "loop"),
    (0x87e30, "GameClock::GameClock", "timing"),
    (0x86450, "GameClock::Update", "timing"),
    (0x860c0, "GameClock::GetScaledDtSeconds", "timing"),
    (0x85fc0, "GameClock::GetDtSeconds", "timing"),
    (0x86000, "GetTimeSecondsF", "timing"),
    (0x85e60, "MicrosecondsToSeconds", "timing"),
    (0x267a50, "core::InitTimerFrequency", "timing"),
    (0x267aa0, "core::GetTimeTicks", "timing"),
    (0x267e20, "core::ScaleTicks", "timing"),
    (0x267f00, "core::GetMicroseconds", "timing"),
    (0x267f40, "core::GetMicroseconds64", "timing"),
    (0x267f80, "core::GetMilliseconds", "timing"),
    (0x268020, "core::TimerList::Update", "timing"),
    (0x2924e0, "pure3d::GetTimerFrequency", "timing"),
    (0x292500, "pure3d::GetTimerTicks", "timing"),
    (0x31d3f0, "pddiBaseContext::DrawFrameRate", "timing"),
    (0x96740, "DrawFrameRateIcon", "timing"),
    # display mode / back buffer / present
    (0x8dec0, "CPlatform::InitRender", "display"),
    (0x8ecd0, "SetupDisplayInit_1280x720", "display"),
    (0x292560, "pure3d::InitPlatform", "display"),
    (0x292330, "pddiDisplayInit::pddiDisplayInit", "display"),
    (0x292410, "pure3d::DefaultDisplayInit", "display"),
    (0x31ba60, "pure3d::d3dCreateDevice", "display"),
    (0x31ba00, "pure3d::d3dDevice::d3dDevice", "display"),
    (0x31b830, "pure3d::d3dDevice::NewDisplay", "display"),
    (0x31b520, "pure3d::d3dDisplay::d3dDisplay", "display"),
    (0x31ae70, "pure3d::d3dDisplay::InitDisplay", "display"),
    (0x31adf0, "pure3d::d3dDisplay::IsModeAllowed", "display"),
    (0x31b500, "pure3d::d3dDisplay::GetAspectRatio", "display"),
    (0x31b190, "pure3d::d3dDisplay::SwapBuffers", "display"),
    (0x31acc0, "pure3d::d3dDisplay::VBlankCallback", "display"),
    (0x324e00, "pure3d::d3dDevice::NewRenderContext", "display"),
    # projection / FOV / HUD
    (0x323ee0, "pure3d::d3dContext::LoadProjectionMatrix", "projection"),
    (0x323eb0, "pure3d::d3dContext::LoadMatrix", "projection"),
    (0x321520, "pure3d::d3dContext::SetViewportRect", "projection"),
    (0x320c60, "pure3d::d3dContext::ResetTransforms", "projection"),
    (0x2926d0, "pure3d::Camera::SetFOV", "projection"),
    (0x292cc0, "pure3d::Camera::fptan_user_292cc0", "projection"),
    (0x2940f0, "pure3d::Camera::fptan_user_2940f0", "projection"),
    (0x294340, "pure3d::Camera::fptan_user_294340", "projection"),
    (0x9f790, "CGameCamera::ComputeRealFOV", "projection"),
    (0xa97e0, "CGameCamera::Update", "projection"),
    (0xa9400, "CGameCamera::aspect_user_a9400", "projection"),
    (0xa94c0, "CGameCamera::aspect_user_a94c0", "projection"),
    (0x31d830, "pddiBaseContext::DrawWithTempNear", "projection"),
    (0xd6970, "OverlayManager::ctor_aspect", "hud"),
    (0xd6a20, "OverlayManager::aspect_user_d6a20", "hud"),
    (0xd6b20, "OverlayManager::aspect_user_d6b20", "hud"),
    (0xd6c70, "OverlayManager::aspect_user_d6c70", "hud"),
    (0xbd1b0, "FE::aspect_user_bd1b0", "hud"),
    (0xef4f0, "FEScreenBase::vfunc_10", "hud"),
    (0x32f3b0, "d3dRefractVertexShader::hardcoded_640x480", "hud"),
    # boot movies
    (0xc5180, "CFEManager::Update", "boot"),
    (0xc4220, "CFEManager::BootSequence", "boot"),
    (0xc3900, "CFEManager::ShowSplashImage", "boot"),
    (0xbfbe0, "CFEManager::AttractIdleTimer", "boot"),
    (0x1b7310, "CFMVManager::QueueMovie", "boot"),
    (0x1b83c0, "CFMVManager::PlayQueued", "boot"),
    (0x1b8350, "CFMVManager::Start", "boot"),
    (0x1b7f40, "CFMVManager::OpenMovie", "boot"),
    (0x1b73c0, "CFMVManager::AudioTrackFor", "boot"),
    (0x1b7970, "CFMVManager::Finish", "boot"),
]
SEAM_CLASS_RE = r"^(pure3d::(d3d|_?pddi|AdaptPDDI)|core::(I?Controller\w*XBox|ControllerBuffer|XboxDrive|XboxSaveDrive|Platform|Timer|TimerList)|movie::|CRadMovieRenderLoop|audio::ListenerEffectXBox)"


PORTABLE = {"C++ runtime", "CRT: heap/stdio", "CRT: formatting", "CRT: math", "CRT: string/memory"}


def seam_of(va):
    for key, desc, ranges in SEAMS:
        if any(a <= va < b for a, b in ranges):
            return key
    return None


def build_priority(img, out):
    """Seam functions, then QoL functions, then their direct game-code callees."""
    order, seen = [], set()

    def add(va, why):
        if va in img.funcs and img.is_game_func(va) and va not in seen:
            seen.add(va)
            order.append((va, why))

    callers = out["callers"]
    rank = {k: i for i, (k, d, r) in enumerate(SEAMS)}
    plat = sorted((int(c, 16) for c, f in callers.items() if f["platform_calls"]),
                  key=lambda va: (rank.get(callers["0x%x" % va]["seam"], len(rank)), va))
    for va in plat:                                   # 1. every game function that calls the platform
        #    (seam by seam, then the leaks)
        add(va, "seam:" + (callers["0x%x" % va]["seam"] or "leak"))
    seam_cls = set()
    for c in img.classes:
        if re.search(SEAM_CLASS_RE, c):
            seam_cls.add(c)
    for va in img.sorted_entries:                     # 2. the rest of the seam ranges and seam classes
        if seam_of(va):
            add(va, "seam:" + seam_of(va))
        elif any(o[0] in seam_cls for o in img.slot_owner.get(va, ())):
            add(va, "seam-class")
    for va, label, sub in QOL:                        # 3. QoL subsystems
        add(va, "qol:" + sub)
    core = list(order)
    for va, why in core:                              # 4. direct callees of all of the above
        for ins, tgt, rt in img.refs.get(va, ()):
            if "CALL" in rt or "JUMP" in rt:
                kind, real = img.resolve(tgt)
                if kind == "func":
                    add(real, "callee")
    return order


def write_labels(img, path):
    labels = {}
    for va, label, sub in QOL:
        labels["0x%x" % va] = label
    for va, n in IDENTIFIED.items():
        labels["0x%x" % va] = re.sub(r"[^A-Za-z0-9_:]+", "_", n).strip("_")
    for va in range(0x39db08, 0x39dfac, 4):
        n = d3d_data_name(va)
        if n:
            labels["0x%x" % va] = re.sub(r"[^A-Za-z0-9_]+", "_", n).strip("_")
    labels["0x%x" % 0x4d3508] = "g_DisplayModeTable"
    labels["0x%x" % 0x49ca1c] = "g_RequestedBackBufferWidth"
    labels["0x%x" % 0x49ca20] = "g_RequestedBackBufferHeight"
    labels["0x%x" % 0x5554a0] = "g_FrontEndVSync60"
    labels["0x%x" % 0x55549c] = "g_VBlanksSinceSwap"
    labels["0x%x" % 0x49fb40] = "g_BootSequenceStep"
    labels["0x%x" % 0x432480] = "g_Aspect4x3"
    labels["0x%x" % 0x432484] = "g_Aspect16x9"
    labels["0x%x" % 0x4dd839] = "g_ArgPal"
    labels["0x%x" % 0x4dd8e4] = "g_ArgFrameRateIcon"
    json.dump(labels, open(path, "w"), indent=1, sort_keys=True)
    return len(labels)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=B("port/platform_calls.json"))
    ap.add_argument("--summary", action="store_true")
    ap.add_argument("--priority", action="store_true",
                    help="write build/farm/priority.txt and docs/port-priority.txt")
    ap.add_argument("--labels", default=B("port/labels.json"), help="Ghidra label JSON to write")
    args = ap.parse_args()
    img = Image()
    calls, meta, data_refs, hw, game = scan(img)

    callers = collections.defaultdict(set)  # caller -> set(target keys)
    for key, cs in calls.items():
        for c in cs:
            callers[c].add(key)
    for key, cs in data_refs.items():
        for c in cs:
            callers[c].add("data:" + key)
    for c, ins, what in hw:
        callers[c].add("hw:" + what.split(":")[0].split(" ")[0])

    funcs_out = {}
    for c in sorted(callers):
        oc = owner_class(img, c)
        vt = sorted(vtable_refs(img, c))
        nb = [] if oc else neighbourhood_class(img, c)
        guess = oc or (vt[0] if len(vt) == 1 else None) or (nb[0][0] if nb else None)
        funcs_out["0x%x" % c] = {
            "name": img.funcs[c]["name"],
            "size": img.funcs[c].get("size"),
            "class": oc,
            "class_guess": guess,
            "class_evidence": "vtable slot" if oc else ("vftable ref" if len(vt) == 1 else ("neighbours %s" % ", ".join("%s:%.2f" % t for t in nb) if nb else "none")),
            "calls": sorted(callers[c]),
        }

    sub_of = {k: classify(k) for k in calls}
    sub_of.update({"data:" + k: classify(k) for k in data_refs})
    seams_out = {k: {"description": d, "ranges": [["0x%x" % a, "0x%x" % b] for a, b in r],
                     "functions": {}, "classes": collections.Counter(), "apis": collections.Counter()}
                 for k, d, r in SEAMS}
    leaks, crt_only = {}, {}
    for c, f in funcs_out.items():
        va = int(c, 16)
        plat = [x for x in f["calls"] if sub_of.get(x, "hardware") not in PORTABLE]
        f["seam"] = seam_of(va)
        f["platform_calls"] = plat
        if f["seam"]:
            so = seams_out[f["seam"]]
            if plat:
                so["functions"][c] = f["name"]
                so["classes"][f["class_guess"] or "?"] += 1
                for x in plat:
                    so["apis"][x] += 1
        elif plat:
            leaks[c] = {"name": f["name"], "class_guess": f["class_guess"], "evidence": f["class_evidence"],
                        "calls": plat, "subsystems": sorted({sub_of.get(x, "hardware") for x in plat})}
        else:
            crt_only[c] = f["name"]
    for so in seams_out.values():
        so["classes"] = dict(so["classes"].most_common())
        so["apis"] = dict(so["apis"].most_common())

    targets = {}
    for key, cs in sorted(calls.items()):
        targets[key] = dict(meta[key], subsystem=classify(key), call_sites=sum(cs.values()),
                            callers={"0x%x" % c: n for c, n in sorted(cs.items())})
    datas = {k: {"subsystem": classify(k), "refs": sum(v.values()), "callers": {"0x%x" % c: n for c, n in sorted(v.items())}}
             for k, v in sorted(data_refs.items())}
    out = {
        "generated_by": "tools/platform_map.py",
        "game_functions": len(game),
        "lib_spans_in_text": [{"start": "0x%x" % a, "end": "0x%x" % b, "label": l} for a, b, l in LIB_SPANS],
        "kernel_thunk_table": "0x%x" % img.kthunk_va,
        "kernel_imports": {"0x%x" % va: "%d:%s" % t for va, t in sorted(img.kthunk.items())},
        "targets": targets,
        "data_refs": datas,
        "hardware": [{"caller": "0x%x" % c, "insn": "0x%x" % i, "what": w} for c, i, w in hw],
        "seams": seams_out,
        "leaks": leaks,
        "crt_only_callers": len(crt_only),
        "callers": funcs_out,
    }
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    order = build_priority(img, out)
    out["priority"] = [{"address": "0x%08x" % va, "why": why, "size": img.funcs[va].get("size", 0),
                        "matched": os.path.exists(os.path.join(ROOT, "matches", "0x%08x.cpp" % va))}
                       for va, why in order]
    json.dump(out, open(args.out, "w"), indent=1)
    nl = write_labels(img, args.labels)
    print("wrote %s: %d labels" % (args.labels, nl))
    if args.priority:
        text = "".join("0x%08x\n" % va for va, why in order)
        for path in (B("farm/priority.txt"), os.path.join(ROOT, "docs/port-priority.txt")):
            with open(path, "w") as f:
                f.write(text)
            print("wrote %s: %d functions" % (path, len(order)))
    groups = collections.OrderedDict()
    for p in out["priority"]:
        g = p["why"].split(":")[0]
        a = groups.setdefault(g, [0, 0, 0, 0])
        a[0] += 1
        a[1] += p["size"]
        a[2] += p["matched"]
        a[3] += p["size"] if p["matched"] else 0
    tot = [sum(a[i] for a in groups.values()) for i in range(4)]
    for g, a in list(groups.items()) + [("total", tot)]:
        print("priority %-10s %5d functions %8d bytes, matched %5d (%d bytes, %.0f%%)"
              % (g, a[0], a[1], a[2], a[3], 100.0 * a[3] / max(1, a[1])))
    print("wrote %s: %d platform targets, %d data symbols, %d hw sites, %d game callers"
          % (args.out, len(targets), len(datas), len(hw), len(funcs_out)))
    if args.summary:
        by = collections.defaultdict(list)
        for k, t in targets.items():
            by[t["subsystem"]].append((t["call_sites"], k, len(t["callers"])))
        for sub in sorted(by):
            rows = sorted(by[sub], reverse=True)
            print("\n## %s: %d functions, %d call sites" % (sub, len(rows), sum(r[0] for r in rows)))
            for n, k, nc in rows:
                print("  %5d sites %4d callers  %s" % (n, nc, k))
        print("\n## data refs")
        for k, d in sorted(datas.items(), key=lambda kv: -kv[1]["refs"]):
            print("  %5d refs %4d funcs  %s  [%s]" % (d["refs"], len(d["callers"]), k, d["subsystem"]))
        print("\n## seams")
        for k, so in seams_out.items():
            print("  %-14s %3d platform-calling functions, %3d distinct APIs  classes: %s"
                  % (k, len(so["functions"]), len(so["apis"]), ", ".join(list(so["classes"])[:8])))
        print("\n## leaks (platform calls outside the seams): %d functions" % len(leaks))
        for c, l in sorted(leaks.items()):
            print("  %s %-28s %-40s %s" % (c, l["name"][:28], (l["class_guess"] or "?")[:40], " ".join(l["calls"])[:120]))
        print("\n## callers that only use portable CRT: %d" % len(crt_only))
        print("\n## hardware")
        for c, i, w in hw:
            print("  %s @0x%x  %s" % (img.funcs[c]["name"], i, w))


if __name__ == "__main__":
    main()

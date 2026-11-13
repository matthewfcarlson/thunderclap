#!/bin/bash
# Bring up an x86-64 Linux host (Debian/Ubuntu/SteamOS-style or Fedora) for the shared job queue (tools/jobq.py,
# docs/compute.md "Adding a host"). The Linux counterpart of tools/jobq_host_setup.sh (macOS), with one difference:
# it runs ON the new box, from a checkout of this repo there, not from the laptop over ssh. It is idempotent: every
# step checks first and only does what is missing. --check (the default) changes nothing and reports each piece; it
# exits 1 when something required is missing.
#
#   tools/jobq_host_setup_linux.sh [--check]                  # what is there, what is missing (default)
#   tools/jobq_host_setup_linux.sh --install [--gfx]          # install what is missing (sudo for packages)
#   tools/jobq_host_setup_linux.sh --data SRC                 # rsync the game data from SRC (a checkout root:
#                                                             #   a local path or an rsync remote spec, USER@HOST:PATH)
#   tools/jobq_host_setup_linux.sh --register NAME [--slots N] [--route USER@HOST]
#                                                             # print the hosts.json entry and the command that adds it
# Options: --dir DIR  the host's checkout the jobs symlink into (default ~/hulk-permute; must be under $HOME, hosts.json
#          "dir" is relative to it). --gfx: also check/install Xvfb (only for wine-gfx runs, which stay on the laptop
#          today; the default caps never include wine-gfx).
#
# Pieces (the same the Mac hosts have, docs/compute.md "Adding a host"): x86-64 Linux, packages (git rsync ssh curl xz
# binutils), sshd + key login (the queue uses BatchMode=yes), Python 3.12 venv (build/venv with the pinned packages),
# LLVM 22.1.8 in ~/llvm (llvm.org's release tarball), MSVC 7.1 (tools/pull_compiler.py) + wibo (build/tools/wibo),
# Wine able to run 32-bit PE (i386/WoW64), the tracked sources (git archive HEAD), the queue's runner
# (~/hulk-jobs/jobq_run.py), disk space, the game data (never fetched by this script except with --data from a source
# you name). Optional (warned, not required): ffmpeg shared libraries and SDL3 build deps for the native x86-64 Linux
# image (headless replays need neither: the image links a static headless SDL3, tools/native_linux_sdl.py), Xvfb (--gfx).
#
# Steps that need the user: sudo for packages and sshd, adding the controller's ssh key to ~/.ssh/authorized_keys,
# keeping the box awake (no suspend), the game data (--data), and adding the entry to the controller's hosts.json.
set -eu

MODE=check; NAME=""; SLOTS=""; ROUTE=""; DATA_SRC=""; GFX=0; HOST_DIR="$HOME/hulk-permute"
usage() { sed -n '2,27p' "$0"; }
while [ $# -gt 0 ]; do
  case "$1" in
    --check) MODE=check ;;
    --install) MODE=install ;;
    --data) [ $# -ge 2 ] || { usage >&2; exit 2; }; MODE=data; DATA_SRC="$2"; shift ;;
    --register) [ $# -ge 2 ] || { usage >&2; exit 2; }; MODE=register; NAME="$2"; shift ;;
    --slots) [ $# -ge 2 ] || { usage >&2; exit 2; }; SLOTS="$2"; shift ;;
    --route) [ $# -ge 2 ] || { usage >&2; exit 2; }; ROUTE="$2"; shift ;;
    --dir) [ $# -ge 2 ] || { usage >&2; exit 2; }; HOST_DIR="$2"; shift ;;
    --gfx) GFX=1 ;;
    -h|--help) usage; exit 0 ;;
    *) echo "unknown argument: $1" >&2; usage >&2; exit 2 ;;
  esac
  shift
done

say() { printf '%-10s %s\n' "$1" "$2"; }
FAIL=0
TODO=()
need_user() { TODO+=("$1"); FAIL=1; }
doit() { [ "$MODE" = install ]; }

# --- platform (before anything else: this is not the Mac script)
OS=$(uname -s); ARCH=$(uname -m)
if [ "$OS" != Linux ]; then
  echo "this is the Linux host setup; on $OS use tools/jobq_host_setup.sh (macOS, run from the laptop over ssh)" >&2
  exit 2
fi
[ "$ARCH" = x86_64 ] || { echo "not an x86-64 host ($ARCH)" >&2; exit 2; }
DISTRO="unknown"; LIKE=""
if [ -r /etc/os-release ]; then
  # shellcheck disable=SC1091
  DISTRO=$(. /etc/os-release && echo "${ID:-unknown} ${VERSION_ID:-}")
  # shellcheck disable=SC1091
  LIKE=$(. /etc/os-release && echo "${ID:-} ${ID_LIKE:-}")
fi
if command -v apt-get >/dev/null 2>&1; then PM=apt
elif command -v dnf >/dev/null 2>&1; then PM=dnf
else PM=none; fi
case " $LIKE " in *" steamos "*|*" arch "*) [ "$PM" = none ] && PM=pacman ;; esac
say linux "$DISTRO $ARCH, $(nproc) cpus, packages: $PM"

cd "$(dirname "$0")/.." || exit 2
ROOT=$PWD
[ -f tools/jobq.py ] && [ -f tools/jobq_run.py ] || { echo "run from a checkout of the repo (tools/jobq.py missing)" >&2; exit 2; }
case "$HOST_DIR" in "$HOME"/*) ;; *) echo "--dir must be under \$HOME (hosts.json \"dir\" is relative to it)" >&2; exit 2 ;; esac
HOST_REL=${HOST_DIR#"$HOME"/}

# Pinned like tools/jobq_host_setup.sh (and docs/compute.md): the toolchain stamp of a Wine build lineage includes
# clang's version and Python's minor version.
PIP_PKGS="capstone==5.0.9 unicorn==2.1.4 clang==21.1.7"
LLVM_VER=22.1.8
LLVM_TAR=LLVM-$LLVM_VER-Linux-X64.tar.xz
LLVM_REL=https://github.com/llvm/llvm-project/releases/download/llvmorg-$LLVM_VER/$LLVM_TAR
# TODO: pin the tarball's SHA-256. The Mac script verifies nothing (it copies a reference host's ~/llvm and compares
# clang++'s hash); --install prints the SHA-256 of what it downloaded so it can be pinned here. Empty: not verified.
LLVM_SHA256=""
LLVM_DIR="$HOME/llvm"
# wibo for x86-64 Linux (the Macs run 1.2.0's wibo-macos under Rosetta, docs/toolchain.md). The release's Linux asset
# name is tried in this order. TODO: pin the SHA-256 (printed by --install); empty: not verified.
WIBO_VER=1.2.0
WIBO_ASSETS="wibo-x86_64 wibo"
WIBO_SHA256=""
MSVC_SUB=build/compilers/msvc7.1/compilers/win32/msvc7.1
CL="$HOST_DIR/$MSVC_SUB/Bin/cl.exe"
WIBO="$HOST_DIR/build/tools/wibo"
VENV="$HOST_DIR/build/venv"
# The queue's runner (tools/jobq_run.py) turns a job's argv0 `wine64`/`wine` into $WINE or ~/wine-whisky/Wine/bin/wine64
# (the Macs' copy of Whisky's Wine), and tools/wine_run.py / wine_replay_job.py look there too. On Linux that path is a
# symlink to the distribution's `wine`, so no tool needs a Linux case. TODO: a per-host "wine" in hosts.json would be
# cleaner.
WINE_SHIM="$HOME/wine-whisky/Wine/bin/wine64"

SUDO=""; [ "$(id -u)" = 0 ] || SUDO=sudo
TMPD=$(mktemp -d); trap 'rm -rf "$TMPD"' EXIT

# ------------------------------------------------------------------------------------------------- --data SRC
if [ "$MODE" = data ]; then
  command -v rsync >/dev/null 2>&1 || { echo "rsync is missing: run --install first" >&2; exit 1; }
  SRC=${DATA_SRC%/}
  mkdir -p "$HOST_DIR/isos/extracted" "$HOST_DIR/build"
  # The player's own copy: the extracted disc (2.3 GB, with default.xbe) and the two tables equivalence jobs read
  # from the host's checkout (docs/compute.md "Adding a host" step 5).
  rsync -a --info=progress2 "$SRC/isos/extracted/" "$HOST_DIR/isos/extracted/"
  rsync -a "$SRC/build/functions.csv" "$SRC/build/rtti.json" "$HOST_DIR/build/"
  say data "copied from $SRC into $HOST_DIR (isos/extracted, build/functions.csv, build/rtti.json)"
  exit 0
fi

# ------------------------------------------------------------------------------------------------- --register NAME
if [ "$MODE" = register ]; then
  case "$NAME" in ''|*[!A-Za-z0-9_-]*) echo "--register NAME: letters, digits, - and _ only" >&2; exit 2 ;; esac
  # The runner needs Python 3.9+ (stdlib only); hosts.json "python" names the venv's when the system one is older.
  RUNPY=""
  python3 -c 'import sys; assert sys.version_info >= (3, 9)' 2>/dev/null || RUNPY="~/$HOST_REL/build/venv/bin/python"
  ROUTE=${ROUTE:-$(id -un)@$(hostname -f 2>/dev/null || hostname)}
  SL=${SLOTS:-$(nproc)}
  # caps: the Macs' "equiv msvc clang wine" (never xemu, never wine-gfx), plus "linux-x64": a new cap naming a host
  # that can run the native x86-64 Linux image (tools/native_elf.py --target linux-x64; docs/native-float64.md "The
  # x86-64 Linux replay"): `jobq.py submit --needs linux-x64` lands on such a host and never on a Mac.
  ENTRY=$(python3 - "$NAME" "$ROUTE" "$SL" "$HOST_REL" "$RUNPY" <<'EOF'
import json, sys
name, route, slots, d, py = sys.argv[1:6]
e = {"name": name, "slots": int(slots), "dir": d, "routes": [[route]], "caps": ["equiv", "msvc", "clang", "wine", "linux-x64"],
     "pref": 0, "path": ["~/llvm/bin"]}
if py:
    e["python"] = py
print(json.dumps(e))
EOF
)
  echo "hosts.json entry (check the route: it is how the controller reaches this box; add a fallback route by hand):"
  echo "  $ENTRY"
  echo
  echo "Run --check first (it must pass). Then, on the controller, from its repo root (the same merge as"
  echo "tools/jobq_host_setup.sh --register: keeps caps, routes, xemu_max and pref you edited there):"
  cat <<EOF
build/venv/bin/python - '$ENTRY' <<'PY'
import json, os, sys
sys.path.insert(0, "tools")
import jobq
e = json.loads(sys.argv[1])
path = os.environ.get("JOBQ_HOSTS") or os.path.join(jobq.JOBS, "hosts.json")
jobq.load_hosts()
d = json.load(open(path))
old = next((h for h in d["hosts"] if h["name"] == e["name"]), None)
if old:
    for k in ("caps", "routes", "xemu_max", "pref"):
        if k in old:
            e[k] = old[k]
    d["hosts"][d["hosts"].index(old)] = e
else:
    d["hosts"].append(e)
json.dump(d, open(path + ".tmp", "w"), indent=1)
os.replace(path + ".tmp", path)
print("hosts.json: %s %s" % ("updated" if old else "added", e["name"]))
PY
EOF
  echo "A running queue daemon picks it up within 30 s; tools/jobq.py status shows it."
  exit 0
fi

# ------------------------------------------------------------------------------------------------- --check / --install
pkg_install() {   # PKG...
  [ $# -gt 0 ] || return 0
  case "$PM" in
    apt) $SUDO apt-get install -y --no-install-recommends "$@" ;;
    dnf) $SUDO dnf install -y "$@" ;;
    *) echo "no apt-get or dnf: install these yourself: $*" >&2; return 1 ;;
  esac
}
apt_has() { apt-cache show "$1" >/dev/null 2>&1; }

# --- packages: a command (or file test) each, with its Debian and Fedora package names
REQ_PKGS=(); OPT_PKGS=()
want() {   # required|optional CMD DEB RPM
  if command -v "$2" >/dev/null 2>&1; then return 0; fi
  local p; if [ "$PM" = dnf ]; then p=$4; else p=$3; fi
  if [ "$1" = required ]; then REQ_PKGS+=("$p"); else OPT_PKGS+=("$p"); fi
}
want required git git git
want required rsync rsync rsync
want required ssh openssh-client openssh-clients
want required curl curl curl
want required xz xz-utils xz
want required ar binutils binutils          # tools/linux_sysroot.py unpacks .debs with ar
want required sha256sum coreutils coreutils
want required python3 python3 python3       # the queue's runner (stdlib, 3.9+)
want optional pkg-config pkg-config pkgconf-pkg-config
want optional cmake cmake cmake
want optional ninja ninja-build ninja-build
[ "$GFX" = 1 ] && want optional Xvfb xvfb xorg-x11-server-Xvfb
[ -x /usr/sbin/sshd ] || [ -x /usr/bin/sshd ] || REQ_PKGS+=(openssh-server)   # sshd is not on a user's PATH
if [ ${#REQ_PKGS[@]} -gt 0 ] && [ -n "${REQ_PKGS[*]// /}" ] && doit; then
  [ "$PM" = apt ] && $SUDO apt-get update -q
  # shellcheck disable=SC2068
  pkg_install ${REQ_PKGS[@]} && REQ_PKGS=()
fi
if [ ${#REQ_PKGS[@]} -gt 0 ] && [ -n "${REQ_PKGS[*]// /}" ]; then
  say packages "MISSING: $(echo ${REQ_PKGS[@]})"; FAIL=1
else say packages ok; fi

# --- sshd: the controller logs in here with BatchMode=yes (key only)
SSHD_ON=0
for s in ssh sshd; do systemctl is-active --quiet "$s" 2>/dev/null && SSHD_ON=1; done
if [ "$SSHD_ON" = 0 ] && doit && command -v systemctl >/dev/null 2>&1; then
  for s in ssh sshd; do systemctl list-unit-files "$s.service" 2>/dev/null | grep -q "^$s.service" &&
    $SUDO systemctl enable --now "$s" && SSHD_ON=1 && break; done
fi
if [ "$SSHD_ON" = 1 ]; then say sshd running; else say sshd "not running"; need_user "enable sshd: sudo systemctl enable --now ssh (Debian/Ubuntu) or sshd (Fedora, SteamOS)"; fi
if [ -s "$HOME/.ssh/authorized_keys" ]; then say ssh-keys "authorized_keys present (the controller's key must be in it)"
else say ssh-keys "no ~/.ssh/authorized_keys"; need_user "on the controller: ssh-copy-id USER@THISBOX (the queue logs in with BatchMode=yes)"; fi

# --- Wine with 32-bit PE support (the Wine build is an i686 image)
wine_i386() {
  local d
  for d in /usr/lib/wine /usr/lib64/wine /usr/lib/i386-linux-gnu/wine /usr/lib/x86_64-linux-gnu/wine \
           /opt/wine-stable/lib/wine /opt/wine-staging/lib/wine /opt/wine-devel/lib/wine /usr/local/lib/wine; do
    [ -f "$d/i386-windows/kernel32.dll" ] && return 0
  done
  return 1
}
if { ! command -v wine >/dev/null 2>&1 || ! wine_i386; } && doit; then
  case "$PM" in
    apt)
      dpkg --print-foreign-architectures | grep -qx i386 || { $SUDO dpkg --add-architecture i386 && $SUDO apt-get update -q; } || true
      W=(wine wine32:i386); apt_has wine64 && W+=(wine64)
      pkg_install "${W[@]}" || true ;;
    dnf)
      # older Fedora: wine pulls wine-core.i686; newer ones ship a WoW64 wine that runs 32-bit PE itself
      pkg_install wine || true; wine_i386 || pkg_install wine-core.i686 || true ;;
    *) need_user "install Wine with 32-bit support (e.g. pacman -S wine)" ;;
  esac
fi
if command -v wine >/dev/null 2>&1 && wine_i386; then say wine "ok ($(wine --version 2>/dev/null), i386 PE)"
elif command -v wine >/dev/null 2>&1; then say wine "$(wine --version 2>/dev/null) but no i386 support"; FAIL=1
  need_user "add 32-bit Wine: Debian/Ubuntu 'sudo dpkg --add-architecture i386 && sudo apt-get update && sudo apt-get install wine32:i386'; Fedora 'sudo dnf install wine-core.i686'"
else say wine MISSING; FAIL=1; fi
if command -v wine >/dev/null 2>&1; then
  WBIN=$(command -v wine)
  if [ "$(readlink "$WINE_SHIM" 2>/dev/null)" = "$WBIN" ]; then say wine-path "ok (~/wine-whisky/Wine/bin/wine64 -> $WBIN)"
  elif doit; then mkdir -p "$(dirname "$WINE_SHIM")" && ln -sfn "$WBIN" "$WINE_SHIM" && say wine-path "linked ~/wine-whisky/Wine/bin/wine64 -> $WBIN"
  else say wine-path "MISSING (~/wine-whisky/Wine/bin/wine64, the path the runner gives wine64 jobs)"; FAIL=1; fi
fi
[ "$GFX" = 1 ] && { command -v Xvfb >/dev/null 2>&1 && say xvfb ok || say xvfb "missing (only for wine-gfx runs)"; }

# --- Python 3.12 venv
find_py312() {
  local p u
  for p in "$(command -v python3.12 2>/dev/null || true)" "$HOME/.local/bin/python3.12"; do
    [ -n "$p" ] && [ -x "$p" ] && "$p" -c 'import venv, ensurepip' 2>/dev/null && { echo "$p"; return 0; }
  done
  for u in "$HOME/.local/bin/uv" "$HOME/.cargo/bin/uv"; do [ -x "$u" ] && "$u" python find 3.12 2>/dev/null && return 0; done
  return 1
}
venv_ok() {
  "$VENV/bin/python" -c 'import sys; assert sys.version_info[:2] == (3, 12)' 2>/dev/null || return 1
  "$VENV/bin/python" -m pip freeze 2>/dev/null > "$TMPD/freeze" || return 1
  local p; for p in $PIP_PKGS; do grep -qx "$p" "$TMPD/freeze" || return 1; done
}
if venv_ok; then say python "ok (3.12 venv, $PIP_PKGS)"
elif doit; then
  PY=$(find_py312 || true)
  if [ -z "$PY" ]; then
    case "$PM" in
      apt) if apt_has python3.12 && apt_has python3.12-venv; then pkg_install python3.12 python3.12-venv || true; fi ;;
      dnf) pkg_install python3.12 || true ;;
    esac
    PY=$(find_py312 || true)
  fi
  if [ -z "$PY" ]; then   # no distribution 3.12 (Debian 12 has 3.11): uv's, as on the Macs (downloads)
    say python "installing uv and Python 3.12 (downloads)"
    { [ -x "$HOME/.local/bin/uv" ] || curl -LsSf https://astral.sh/uv/install.sh | sh; } &&
      "$HOME/.local/bin/uv" python install 3.12 && PY=$("$HOME/.local/bin/uv" python find 3.12 || true)
  fi
  if [ -z "$PY" ]; then need_user "install Python 3.12 (python3.12 + python3.12-venv, or uv python install 3.12), then rerun"
  else
    mkdir -p "$HOST_DIR/build"
    { [ -x "$VENV/bin/python" ] || "$PY" -m venv "$VENV"; } &&
      "$VENV/bin/python" -m pip install -q --upgrade pip && "$VENV/bin/python" -m pip install -q $PIP_PKGS || true
    if venv_ok; then say python "ok (venv from $PY)"; else need_user "pip install into $VENV failed: $VENV/bin/python -m pip install $PIP_PKGS"; fi
  fi
else say python "MISSING or incomplete (3.12 venv at $VENV with $PIP_PKGS)"; FAIL=1; fi
if python3 -c 'import sys; assert sys.version_info >= (3, 9)' 2>/dev/null; then say runner-py "python3 ($(python3 -V 2>&1))"
else say runner-py "system python3 older than 3.9: --register names the venv's"; fi

# --- LLVM: llvm.org's release, the same version as every queue host's (clang's version is in the toolchain stamp)
llvm_ok() {
  "$LLVM_DIR/bin/clang++" --version 2>/dev/null | head -1 | grep -qE "clang version $LLVM_VER( |$)" || return 1
  local t; for t in clang ld.lld lld-link llvm-nm llvm-undname; do [ -x "$LLVM_DIR/bin/$t" ] || return 1; done
  [ -f "$LLVM_DIR/lib/libclang.so" ]   # tools/equiv64.py loads it for the --x64 check
}
if llvm_ok; then say llvm "ok ($("$LLVM_DIR/bin/clang++" --version | head -1))"
elif doit; then
  say llvm "downloading $LLVM_TAR (about 2 GB)"
  mkdir -p "$TMPD/llvm-dl"
  if curl -fL --retry 3 -o "$TMPD/llvm-dl/$LLVM_TAR" "$LLVM_REL"; then
    GOT=$(sha256sum "$TMPD/llvm-dl/$LLVM_TAR" | cut -d' ' -f1)
    if [ -n "$LLVM_SHA256" ] && [ "$GOT" != "$LLVM_SHA256" ]; then say llvm "SHA-256 MISMATCH ($GOT)"; FAIL=1
    else
      [ -n "$LLVM_SHA256" ] || say llvm "sha256 $GOT (not pinned: TODO set LLVM_SHA256 in this script)"
      rm -rf "$LLVM_DIR.new" && mkdir -p "$LLVM_DIR.new" &&
        tar -xJf "$TMPD/llvm-dl/$LLVM_TAR" -C "$LLVM_DIR.new" --strip-components 1 &&
        rm -rf "$LLVM_DIR" && mv "$LLVM_DIR.new" "$LLVM_DIR"
      if llvm_ok; then say llvm "ok ($("$LLVM_DIR/bin/clang++" --version | head -1))"; else say llvm "installed but not working"; FAIL=1; fi
    fi
  else say llvm "download FAILED ($LLVM_REL)"; FAIL=1; fi
else say llvm "MISSING or not $LLVM_VER in ~/llvm (clang++, ld.lld, lld-link, llvm-nm, llvm-undname, lib/libclang.so)"; FAIL=1; fi

# --- tracked sources: what jobs symlink from the host's checkout (src/ docs/ ...)
if [ "$(realpath "$ROOT")" = "$(realpath -m "$HOST_DIR")" ]; then say sources "this checkout ($(git rev-parse --short HEAD 2>/dev/null || echo '?'))"
else
  HEADC=$(git rev-parse --short HEAD 2>/dev/null || true)
  [ -n "$HEADC" ] || { say sources "$ROOT is not a git checkout: clone the repo, or run from $HOST_DIR"; exit 1; }
  HOSTC=$(cat "$HOST_DIR/.jq-setup-commit" 2>/dev/null || true)
  if [ -n "$HOSTC" ] && ! doit; then say sources "from $HOSTC (HEAD $HEADC)"
  elif doit; then
    mkdir -p "$HOST_DIR" &&
      git archive HEAD include src tools config tests | tar -x -C "$HOST_DIR" &&
      echo "$HEADC" > "$HOST_DIR/.jq-setup-commit" && say sources "HEAD $HEADC into $HOST_DIR"
  else say sources "none in $HOST_DIR (--install copies git archive HEAD)"; FAIL=1; fi
fi

# --- MSVC 7.1 (decomp.me's image, tools/pull_compiler.py) and wibo
if [ ! -f "$CL" ] && doit; then
  PYC="$VENV/bin/python"; [ -x "$PYC" ] || PYC=python3
  mkdir -p "$HOST_DIR/build/compilers" && "$PYC" "$HOST_DIR/tools/pull_compiler.py" win32/msvc7.1 "$HOST_DIR/build/compilers/msvc7.1" || true
fi
if [ -f "$CL" ]; then say msvc "ok (cl.exe sha1 $(sha1sum "$CL" | cut -c1-12): must equal the controller's, shasum $MSVC_SUB/Bin/cl.exe)"
else say msvc "MISSING ($MSVC_SUB)"; FAIL=1; fi
if [ ! -x "$WIBO" ] && doit; then
  mkdir -p "$HOST_DIR/build/tools" "$TMPD/wibo-dl"
  for a in $WIBO_ASSETS; do
    if curl -fsL -o "$TMPD/wibo-dl/wibo" "https://github.com/decompals/wibo/releases/download/$WIBO_VER/$a"; then
      GOT=$(sha256sum "$TMPD/wibo-dl/wibo" | cut -d' ' -f1)
      if [ -n "$WIBO_SHA256" ] && [ "$GOT" != "$WIBO_SHA256" ]; then say wibo "SHA-256 MISMATCH for $a ($GOT)"; continue; fi
      [ -n "$WIBO_SHA256" ] || say wibo "$a sha256 $GOT (not pinned: TODO set WIBO_SHA256 in this script)"
      install -m 755 "$TMPD/wibo-dl/wibo" "$WIBO" && break
    fi
  done
fi
if [ -x "$WIBO" ] && [ -f "$CL" ] && "$WIBO" "$CL" 2>&1 | grep -q "Optimizing Compiler"; then say wibo "ok (runs cl.exe)"
elif [ -x "$WIBO" ]; then say wibo "present but cl.exe does not run under it"; FAIL=1
else say wibo "MISSING (build/tools/wibo)"; FAIL=1; fi
# Wine runs a 32-bit PE end to end (cl.exe is one), in a throwaway prefix; --install only (the first run takes a while)
if doit && [ -f "$CL" ] && command -v wine >/dev/null 2>&1; then
  if WINEPREFIX="$TMPD/wpfx" WINEDEBUG=-all WINEDLLOVERRIDES="mscoree,mshtml=" DISPLAY="" timeout 300 wine "$CL" 2>&1 |
     grep -q "Optimizing Compiler"; then say wine-run "ok (cl.exe under Wine)"
  else say wine-run "FAILED: wine cannot run cl.exe (32-bit PE)"; FAIL=1; fi
fi

# --- the queue's runner (the daemon reinstalls it on every connect); workspaces live in ~/hulk-jobs
if doit; then mkdir -p "$HOME/hulk-jobs" && cp tools/jobq_run.py "$HOME/hulk-jobs/jobq_run.py"; fi
if python3 "$HOME/hulk-jobs/jobq_run.py" probe >/dev/null 2>&1; then say runner ok
else say runner "not installed (~/hulk-jobs/jobq_run.py; --install or the daemon's first connect copies it)"; fi

# --- optional: the native x86-64 Linux image for play (headless replays link a static SDL3 and need neither)
LDC=$(command -v ldconfig || echo /sbin/ldconfig)
if "$LDC" -p 2>/dev/null | grep -q 'libavcodec\.so\.'; then say ffmpeg "ok (shared libraries)"
else say ffmpeg "missing (optional: Bink movies play through FFmpeg loaded at runtime)"
  if [ "$PM" = dnf ]; then OPT_PKGS+=(ffmpeg-free); else OPT_PKGS+=(ffmpeg); fi; fi
SDLPC="x11 xext xkbcommon wayland-client libpulse alsa libudev"
# shellcheck disable=SC2086
if command -v pkg-config >/dev/null 2>&1 && pkg-config --exists $SDLPC 2>/dev/null; then say sdl3-deps ok
else say sdl3-deps "missing (optional: SDL3's X11/Wayland/Pulse/ALSA dev packages; headless runs need none)"
  if [ "$PM" = dnf ]; then OPT_PKGS+=(libX11-devel libXext-devel libxkbcommon-devel wayland-devel pulseaudio-libs-devel alsa-lib-devel systemd-devel)
  else OPT_PKGS+=(libx11-dev libxext-dev libxkbcommon-dev libwayland-dev libpulse-dev libasound2-dev libudev-dev); fi; fi
if [ ${#OPT_PKGS[@]} -gt 0 ] && [ -n "${OPT_PKGS[*]// /}" ]; then
  # shellcheck disable=SC2068
  if doit; then pkg_install ${OPT_PKGS[@]} || say optional "some optional packages failed: $(echo ${OPT_PKGS[@]})"
  else say optional "--install adds: $(echo ${OPT_PKGS[@]})"; fi
fi

# --- disk: LLVM about 2 GB, game data 2.3 GB, compilers, venv, plus the queue's lineages and caches in ~/hulk-jobs
FREE_GB=$(( $(df -Pk "$HOME" | awk 'NR==2 {print $4}') / 1048576 ))
if [ "$FREE_GB" -ge 40 ]; then say disk "ok (${FREE_GB} GB free in \$HOME)"
elif [ "$FREE_GB" -ge 20 ]; then say disk "${FREE_GB} GB free in \$HOME (tight: Wine build lineages grow; 40+ GB advised)"
else say disk "only ${FREE_GB} GB free in \$HOME (20 GB minimum)"; FAIL=1; fi

# --- game data: the player's own, never fetched by this script (except --data SRC, which you run)
DATA=""
for f in isos/extracted/default.xbe isos/extracted/art.rcf build/functions.csv build/rtti.json; do
  [ -f "$HOST_DIR/$f" ] || DATA="$DATA $f"
done
if [ -z "$DATA" ]; then say data ok
else say data "missing:$DATA"; need_user "copy the game data: $0 --data SRC (SRC: a checkout root holding isos/extracted and build/functions.csv, rtti.json; local path or USER@HOST:PATH)"; fi

# --- smoke test: one byte match (wibo + MSVC + venv) in the host's checkout (a tree TU and its first `matches` block)
if [ -z "$DATA" ] && venv_ok && [ -x "$WIBO" ]; then
  M=$(cd "$HOST_DIR" && grep -rlE '^// 0x[0-9a-f]{8} .*\): matches' src/game 2>/dev/null | head -1 || true)
  A=$( [ -z "$M" ] || grep -m1 -oE '^// 0x[0-9a-f]{8} .*\): matches' "$HOST_DIR/$M" | cut -c4-13)
  if [ -z "$M" ]; then say compare "skipped (no tree TU in $HOST_DIR)"
  elif (cd "$HOST_DIR" && build/venv/bin/python tools/compare.py "$M" "$A" 2>&1 | grep -q MATCH); then
    say compare "ok ($M $A MATCH)"
  else say compare "FAILED ($M)"; FAIL=1; fi
fi

if [ "$FAIL" = 0 ]; then echo; echo "Ready. Next: $0 --register NAME (prints the hosts.json entry for the controller)."; fi
TODO+=("keep the box awake on power (no suspend); build stages run 20-60 min and Linux has no caffeinate")
echo; echo "For the user:"; for t in "${TODO[@]}"; do echo "  - $t"; done
exit $FAIL

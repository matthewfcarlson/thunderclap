#!/bin/sh
# Install Ghidra 12.0.3 + ghidra-xbe into build/tools and import default.xbe into build/ghidra.
# Requires: brew install openjdk@21
set -eu
cd "$(dirname "$0")/.."

GHIDRA_VER=12.0.3
GHIDRA_ZIP=ghidra_${GHIDRA_VER}_PUBLIC_20260210.zip
GHIDRA_SHA=90d3fffb20b00030dcef8d2a24dd0f422d3a61e432b3ad43f77233ac6d667981
XBE_TAG=build-202602250354
XBE_ZIP=ghidra_${GHIDRA_VER}_PUBLIC_20260225_ghidra-xbe.zip
JDK=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home
G=build/tools/ghidra_${GHIDRA_VER}_PUBLIC

mkdir -p build/tools/dl
if [ ! -d "$G" ]; then
    curl -sL -o build/tools/dl/ghidra.zip \
        "https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_${GHIDRA_VER}_build/${GHIDRA_ZIP}"
    echo "$GHIDRA_SHA  build/tools/dl/ghidra.zip" | shasum -a 256 -c
    unzip -q build/tools/dl/ghidra.zip -d build/tools
fi

if [ ! -d "$G/Ghidra/Extensions/ghidra-xbe" ]; then
    curl -sL -o build/tools/dl/ghidra-xbe.zip \
        "https://github.com/XboxDev/ghidra-xbe/releases/download/${XBE_TAG}/${XBE_ZIP}"
    unzip -q build/tools/dl/ghidra-xbe.zip -d "$G/Ghidra/Extensions"
    # Only an x86_64 macOS XbSymbolDatabaseCLI ships; Ghidra on Apple Silicon looks in mac_arm_64 (runs via Rosetta).
    cp -R "$G/Ghidra/Extensions/ghidra-xbe/os/mac_x86_64" "$G/Ghidra/Extensions/ghidra-xbe/os/mac_arm_64"
    chmod +x "$G"/Ghidra/Extensions/ghidra-xbe/os/mac_*/XbSymbolDatabaseCLI
fi

sed -i '' "s|^JAVA_HOME_OVERRIDE=.*|JAVA_HOME_OVERRIDE=${JDK}|" "$G/support/launch.properties"

if [ ! -f build/ghidra/hulk.gpr ]; then
    mkdir -p build/ghidra
    "$G/support/analyzeHeadless" build/ghidra hulk -import isos/extracted/default.xbe > build/ghidra-import.log 2>&1
fi

echo "Open the GUI with: $G/ghidraRun  (project: build/ghidra/hulk.gpr)"

#!/bin/sh
# Run the matching farm. The OpenRouter key comes from pi's credential store at runtime;
# the local LLM endpoint comes from farm/.env.local (gitignored), e.g.:
#   LOCAL_LLM_BASE_URL=http://macbook.local:8080/v1
#   LOCAL_LLM_API_KEY=...
set -eu
cd "$(dirname "$0")/.."
if [ -f farm/.env.local ]; then
    set -a; . farm/.env.local; set +a
fi
OPENROUTER_API_KEY="$(pi auth print-api-key --provider openrouter)" \
    exec node --experimental-strip-types farm/src/farm.ts "$@"

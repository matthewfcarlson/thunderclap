#!/usr/bin/env python3
"""Download a decomp.me compiler image from ghcr.io without Docker.
Usage: tools/pull_compiler.py win32/msvc7.1 build/compilers/msvc7.1"""
import json, sys, urllib.request, tarfile, io
image, out = sys.argv[1], sys.argv[2]   # e.g. win32/msvc7.1
repo = "decompme/compilers"
tok = json.load(urllib.request.urlopen(f"https://ghcr.io/token?scope=repository:{repo}/{image}:pull"))["token"]
def get(path, accept):
    r = urllib.request.Request(f"https://ghcr.io/v2/{repo}/{image}/{path}", headers={"Authorization": f"Bearer {tok}", "Accept": accept})
    return urllib.request.urlopen(r).read()
idx = json.loads(get("manifests/latest", "application/vnd.oci.image.index.v1+json,application/vnd.oci.image.manifest.v1+json,application/vnd.docker.distribution.manifest.v2+json"))
if "manifests" in idx:
    idx = json.loads(get("manifests/" + idx["manifests"][0]["digest"], "application/vnd.oci.image.manifest.v1+json,application/vnd.docker.distribution.manifest.v2+json"))
for layer in idx["layers"]:
    blob = get("blobs/" + layer["digest"], "*/*")
    print("layer", layer["digest"][:19], len(blob))
    with tarfile.open(fileobj=io.BytesIO(blob)) as t:
        t.extractall(out, filter="data")

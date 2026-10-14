#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="build"

if [[ "${1:-}" == "clean" ]]; then
    rm -rf "$BUILD_DIR"
fi

cmake -S . -B "$BUILD_DIR"
cmake --build "$BUILD_DIR" --parallel "$(nproc)"
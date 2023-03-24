#!/bin/bash

export WASI_SDK_PATH=/opt/wasi-sdk
export PYTHON_VERSION=3.10
export SITE_PACKAGES="wasi-python/lib/python${PYTHON_VERSION}/site-packages"

rm -f "udf-python${PYTHON_VERSION}.wasm"
rm -f "s2-udf-python${PYTHON_VERSION}.wasm"

${WASI_SDK_PATH}/bin/clang --target=wasm32-unknown-wasi \
      -mexec-model=reactor \
      -g \
      -D_WASI_EMULATED_GETPID \
      -D_WASI_EMULATED_SIGNAL \
      -D_WASI_EMULATED_PROCESS_CLOCKS \
      -D_WASI_EMULATED_MMAN \
      -I. \
      -Iinclude \
      -Iwasi-python/include/python${PYTHON_VERSION} \
      -isystem include \
      -fno-exceptions \
      -Llib \
      -Wl,--stack-first \
      -Wl,-z,stack-size=83886080 \
      -lwasix -lwasi_vfs -lwasi-emulated-signal -lwasi-emulated-mman \
      -lpthread -lm -luuid -lsqlite3 -lbz2 -lz -llzma -lm \
      -lc-printscan-long-double -lstdc++ \
      udf.c udf_impl.c \
      math-builtins.c \
      ${SITE_PACKAGES}/pandas-*.egg/pandas/_libs/*.a \
      ${SITE_PACKAGES}/pandas-*.egg/pandas/_libs/tslibs/*.a \
      ${SITE_PACKAGES}/pandas-*.egg/pandas/_libs/window/*.a \
      ${SITE_PACKAGES}/pandas-*.egg/pandas/io/sas/*.a \
      ${SITE_PACKAGES}/numpy/random/*.a \
      ${SITE_PACKAGES}/numpy/linalg/*.a \
      ${SITE_PACKAGES}/numpy/fft/*.a \
      ${SITE_PACKAGES}/numpy/core/*.a \
      libnpy*.a \
      wasi-python/lib/libpython${PYTHON_VERSION}.a \
      -o "udf-python${PYTHON_VERSION}.wasm"

if [ ! -f "udf-python${PYTHON_VERSION}.wasm" ]; then
    echo 'BUILD FAILED'
    exit
fi

echo 'BUILD COMPLETE'

wasi-vfs pack udf-python${PYTHON_VERSION}.wasm \
    --mapdir "/opt/wasi-python/lib/python${PYTHON_VERSION}::wasi-python/lib/python${PYTHON_VERSION}" \
    --output "s2-udf-python${PYTHON_VERSION}.wasm"

echo 'DONE'

wasmtime run --env PYTHONDONTWRITEBYTECODE=x s2-udf-python3.10.wasm

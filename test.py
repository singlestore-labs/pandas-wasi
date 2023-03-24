#!/usr/bin/env python3

import wasmtime
from bindings import Udf

store = wasmtime.Store()

module = wasmtime.Module(store.engine, open('s2-udf-python3.10.wasm', 'rb').read())

linker = wasmtime.Linker(store.engine)
linker.define_wasi()

wasi = wasmtime.WasiConfig()

wasi.inherit_stdin()
wasi.inherit_stdout()
wasi.inherit_stderr()

wasi.env = [
    ('PYTHONDONTWRITEBYTECODE', 'x'),
#   ('PYTHONVERBOSE', '5'),
]

#wasi.preopen_dir('/opt/wasi-python/lib/python3.10',
#                 '/opt/wasi-python/lib/python3.10')
#wasi.preopen_dir('/tmp/wasi-udf-python3.10/lib/python3.10/site-packages',
#                 '/opt/wasi-python/lib/python3.10/site-packages')

store.set_wasi(wasi)

udf = Udf(store, linker, module)

# You *must* call _initialize for wasi to work
udf.instance.exports(store)['_initialize'](store)

udf.exec(store, r'''
import platform
print('platform', platform.platform(), '\n')

print('## NUMPY ##\n')

import numpy as np

print('numpy', np.__version__)
print('')

print('a')
a = np.array([2, 3, 4])
print(a)
print(a.dtype)
print('')

print('b')
b = np.array([1.2, 3.5, 5.1])
print(b)
print(b.dtype)
print('')

print('zeros')
print(np.zeros((3, 4)))
print('')

print('ones')
print(np.ones((2, 3, 4)))
print('')

print('empty')
print(np.empty((2, 3)))
print('')

print('int range')
print(np.arange(10, 30, 5))
print('')

print('float range')
print(np.arange(0, 2, 0.3))
print('')

print('linspace')
print(np.linspace(0, 2, 9))
x = np.linspace(0, 2 * np.pi, 100)
f = np.sin(x)
print(f)
print('')

print('a - b')
print(a - b)
print('')

print('b**2')
print(b ** 2)
print('')


print('## PANDAS ##\n')

import pandas as pd

print('pandas', pd.__version__)
print('')

df = pd.DataFrame([[1.234, 2, 'hi'], [3.14, 3, 'bye']], columns=['a', 'b', 'c'])
print('COLUMNS', df.columns)
print('DTYPES', df.dtypes, '\n')
print(df, '\n')

df = pd.DataFrame([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]], columns=['a', 'b', 'c'])
df2 = df * 3.14
print(df2, '\n')

print(df.mean(), '\n')
print(df2.mean(), '\n')
''')

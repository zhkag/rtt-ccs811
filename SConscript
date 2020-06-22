from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

# add ccs811 src files.
if GetDepend('PKG_USING_CCS811'):
    src += Glob('src/ccs811.c')
    src += Glob('src/sensor_sensirion_ccs811.c')

if GetDepend('PKG_USING_CCS811_SAMPLE'):
    src += Glob('examples/ccs811_sample.c')
    src += Glob('examples/sensor_ccs811_sample.c')

# add ccs811 include path.
path  = [cwd + '/inc']

# add src and include to group.
group = DefineGroup('ccs811', src, depend = ['PKG_USING_CCS811'], CPPPATH = path)

Return('group')
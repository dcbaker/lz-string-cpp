# SPDX-License-Identifier: MIT
# Copyright © 2023 Dylan Baker

project(
  'lz-string',
  'cpp',
  version : '0.1-devel',
  meson_version : '>= 0.60',
  default_options : ['cpp_std=c++14', 'b_ndebug=if-release'],
)

cpp = meson.get_compiler('cpp')
conf = configuration_data()

# An unreachable macro.
# for debug builds assert if we hit unreachable code, it's definately a bug use
# builtin functionality if available, and fall back to an assert otherwise
if get_option('debug')
  conf.set('UNREACHABLE', 'assert(false)')
elif cpp.has_define('__GNUC__')
  conf.set('UNREACHABLE', '__builtin_unreachable()')
elif cpp.has_define('_MSC_VER')
  conf.set('UNREACHABLE', '__assume(false)')
else
  conf.set('UNREACHABLE', 'assert(false)')
endif

configure_file(
  configuration : conf,
  output : 'lz-string-config.hpp',
)

inc = include_directories('include')

lib = library(
  'lz-string',
  'src/lz-string.cpp',
  include_directories : inc,
  vs_module_defs : 'src/lz-string.def',
  install : true,
)

install_headers('include/lz-string.hpp')

dep = declare_dependency(
  link_with : lib,
  include_directories : inc,
)

dep_gtest = dependency('gtest_main')

test(
  'main',
  executable(
    'lz-string-test',
    'tests/test.cpp',
    dependencies : [dep, dep_gtest],
  ),
  protocol : 'gtest',
)

meson.override_dependency('lz-string', dep)

pkg = import('pkgconfig')
pkg.generate(
  lib,
  description : 'A C++ implementation of the lz-string compression algorithm'
)

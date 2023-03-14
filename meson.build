# SPDX-License-Identifier: MIT
# Copyright © 2023 Dylan Baker

project(
  'lz-string',
  'cpp',
  version : '0.1-devel',
  meson_version : '>= 0.60',
  default_options : ['cpp_std=c++11'],
)

inc = include_directories('include')

lib = library(
  'lz-string',
  'src/lz-string.cpp',
  include_directories : inc,
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
  )
)

meson.override_dependency('lz-string', dep)

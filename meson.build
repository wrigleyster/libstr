project('libstr', 'cpp', default_options:'cpp_std=c++20')

include = include_directories('inc')

subdir('inc')
subdir('src')

libstr_dep  = declare_dependency(
  include_directories: include,
  link_with: libstr,
)



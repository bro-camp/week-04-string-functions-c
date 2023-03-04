# Build script for C project
import os

src_file_list = [
  '01-string-functions.c',
  '02-string-copy.c',
  '03-char-count.c',
]

# --------------------------------------------------------------------

cwd = os.getcwd()
# Windows path back slash to forward slash
cwd = cwd.replace('\\', '/')

src_dir = cwd + '/' + 'src'
include_dir = cwd + '/' + 'include'
build_dir = cwd + '/' + 'build'

# CREATING BUILD COMMAND LIST
build_command_list = []
for src_file in src_file_list:
  src_file_path = src_dir + '/' + src_file + ' '
  build_file_name_parts = src_file.split('.')
  build_file_name_parts.pop()
  build_file_name = '.'.join(build_file_name_parts)
  build_file_path = build_dir + '/' + build_file_name + '.exe'
  build_command = 'gcc -o ' + build_file_path + ' -I ' + include_dir + ' ' + src_file_path
  build_command_list.append(build_command)

if not os.path.exists(build_dir):
  os.mkdir(build_dir)

# EXECUTING BUILD COMMAND LIST
for build_command in build_command_list:
  # print(build_command) # For debugging
  os.system(build_command)

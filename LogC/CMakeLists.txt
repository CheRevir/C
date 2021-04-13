# 工程名称
project(LogC)

# CMake最低版本
cmake_minimum_required(VERSION 3.20.0)

# 将<dir>赋值给<variable>
#aux_source_directory(<dir> <variable>)

# 添加一个子目录
add_subdirectory(src)

# 生成一个名为test的可执行文件
add_executable(test test.c)

#将LogC链接到test
target_link_libraries(test logc)

cmake_minimum_required(VERSION 3.2)

project(thaistr)

# Sets the prefix for installations
# Optionally uses an environment variable called
# 'THAISTR_HOME'
if(DEFINED $ENV{THAISTR_HOME})
    set(CMAKE_INSTALL_PREFIX $ENV{THAISTR_HOME})
    message("Installing with prefix THAISTR_HOME=$ENV{THAISTR_HOME}")
else(DEFINED $ENV{THAISTR_HOME})
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif(DEFINED $ENV{THAISTR_HOME})


add_subdirectory(build)
add_subdirectory(scripts)


enable_testing()

add_subdirectory(testing)

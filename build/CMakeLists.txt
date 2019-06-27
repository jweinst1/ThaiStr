# cmake for building and installing ThaiStr

# This sets the package specific versioning
set(THAISTR_MAJOR_VERSION 0)
set(THAISTR_MINOR_VERSION 1)
set(THAISTR_PATCH_VERSION 0)

# This allows easy creation of the directories within /usr/local or another install
# prefix
set(THAISTR_NAMED_VERSION thaistr-${THAISTR_MAJOR_VERSION}.${THAISTR_MINOR_VERSION})
set(THAISTR_NAMED_VERSION ${THAISTR_NAMED_VERSION} PARENT_SCOPE)
# For the config header
set(THAISTR_AUTHOR "Joshua Weinstein")
string(TIMESTAMP THAISTR_BUILD_TIME)

file(READ ${PROJECT_SOURCE_DIR}/LICENSE.txt THAISTR_LICENSE)

# These statements will create the directories needed for installs
install(DIRECTORY DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${THAISTR_NAMED_VERSION})
install(DIRECTORY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${THAISTR_NAMED_VERSION})

# This tracks the name of the in files used to generate the package cmake files
set(THAISTR_CONFIG_FILE thaistr-config.cmake.in)
set(THAISTR_CONFIG_VERSION_FILE thaistr-config-version.cmake.in)
set(THAISTR_CONFIG_HEADER_FILE thaistr-config.h.in)

# The configure_file statements will exchange the variables for the values in this cmake file.
configure_file(${THAISTR_CONFIG_FILE} thaistr-config.cmake @ONLY)
configure_file(${THAISTR_CONFIG_VERSION_FILE} thaistr-config-version.cmake @ONLY)
configure_file(${THAISTR_CONFIG_HEADER_FILE} thaistr-config.h @ONLY)

# Installs to the output locations so they can be found with find_package()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/thaistr-config-version.cmake DESTINATION include/${THAISTR_NAMED_VERSION})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/thaistr-config.cmake DESTINATION lib/${THAISTR_NAMED_VERSION})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/thaistr-config.h DESTINATION include/${THAISTR_NAMED_VERSION})

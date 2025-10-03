cmake_minimum_required(VERSION 3.10.0)
project(LAB1 VERSION 0.1.0 LANGUAGES C CXX)

if(DEFINED VERSION_PROJECT)
    add_definitions(-DVERSION_PROJECT="${VERSION_PROJECT}")
else()
    add_definitions(-DVERSION_PROJECT="0.0.0")
endif()

add_executable(LAB1 main.cpp)

# Настройки CPack для DEB пакета
set(CPACK_PACKAGE_NAME "LAB1")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION "Simple Hello World application")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Hello World application for LAB1")
set(CPACK_PACKAGE_VENDOR "Your Name")
set(CPACK_PACKAGE_MAINTAINER "Your Name <your.email@example.com>")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.com>")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/yourusername/LAB1")

# Обязательные настройки для DEB пакета
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)

# Настройки генераторов пакетов
if(WIN32)
    set(CPACK_GENERATOR "ZIP")
endif()

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    # Обязательные поля для DEB пакета
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
endif()

install(TARGETS LAB1 DESTINATION bin)

include(CPack)
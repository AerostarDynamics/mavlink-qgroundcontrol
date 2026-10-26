message(STATUS "QGC: Adding Aerostar custom plugin")

# Enable custom build
set_property(DIRECTORY ${CMAKE_SOURCE_DIR}
    APPEND PROPERTY COMPILE_DEFINITIONS
    QGC_CUSTOM_BUILD
    AEROSTAR_SPLASH_HIDDEN_BY_PLUGIN # AerostarCorePlugin hides the Android start-up screen itself, after a minimum time
    CUSTOMHEADER="AerostarCorePlugin.h"
    CUSTOMCLASS=AerostarCorePlugin
)

if(ANDROID)
    # Overlay custom/android (manifest label, icons, start-up screen) on the stock Android package template
    set(CUSTOM_ANDROID_DIR "${CMAKE_SOURCE_DIR}/custom/android")
    set(DEFAULT_ANDROID_DIR "${CMAKE_SOURCE_DIR}/android")
    set(FINAL_ANDROID_DIR "${CMAKE_BINARY_DIR}/custom/android")
    file(COPY "${DEFAULT_ANDROID_DIR}/." DESTINATION "${FINAL_ANDROID_DIR}")
    # file(COPY) skips a file whose timestamp matches the one already copied from the default
    # template, which happens on a fresh checkout. Copy the custom files by content instead.
    file(GLOB_RECURSE CUSTOM_ANDROID_OVERLAY RELATIVE "${CUSTOM_ANDROID_DIR}" "${CUSTOM_ANDROID_DIR}/*")
    foreach(CUSTOM_FILE IN LISTS CUSTOM_ANDROID_OVERLAY)
        configure_file("${CUSTOM_ANDROID_DIR}/${CUSTOM_FILE}" "${FINAL_ANDROID_DIR}/${CUSTOM_FILE}" COPYONLY)
    endforeach()
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
                    "${DEFAULT_ANDROID_DIR}/"
                    "${CUSTOM_ANDROID_DIR}/"
                )
    set(QGC_ANDROID_PACKAGE_SOURCE_DIR "${FINAL_ANDROID_DIR}" CACHE PATH "Path to a custom Android package template" FORCE)
    message(STATUS "QGC: Android package template path will be set to: ${QGC_ANDROID_PACKAGE_SOURCE_DIR}")
endif()

# Our own, custom resources
list(APPEND CUSTOM_RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/custom.qrc
)
set(QGC_RESOURCES ${QGC_RESOURCES} ${CUSTOM_RESOURCES} CACHE STRING "Paths to .qrc Resources" FORCE)

set(CUSTOM_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AerostarCorePlugin.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AerostarCorePlugin.h
    CACHE INTERNAL "" FORCE
)

set(CUSTOM_INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    CACHE INTERNAL "" FORCE
)

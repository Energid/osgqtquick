# New policies
if(NOT DEFINED OSGQTQUICK_ACTIN_BUILD)
   foreach(policy CMP0020 CMP0022 CMP0043)
     if(POLICY ${policy})
         cmake_policy(SET ${policy} NEW)
     endif()
   endforeach()
endif(NOT DEFINED OSGQTQUICK_ACTIN_BUILD)

list(APPEND CMAKE_MODULE_PATH "${osgQtQuick_ROOT_DIR}/cmake")

# OpenSceneGraph
if(EC_EXT_osg_LIB)
    get_filename_component(OSG_DIR ${EC_EXT_osg_LIB} DIRECTORY)
    if(NOT APPLE)
       get_filename_component(OSG_DIR ${OSG_DIR} DIRECTORY)
    endif(NOT APPLE)
endif(EC_EXT_osg_LIB)

find_package(OpenSceneGraph 3.0 REQUIRED
  osg
  osgDB
  osgGA
  osgManipulator
  osgUtil
  osgViewer
  osgText)

# osgQt
if(osgQtQuick_WITH_OSGQT)
  find_package(osgQt 3.0 REQUIRED)
endif()

# Qt
if(EC_EXT_Qt5Quick_LIB_RELEASE)
   get_filename_component(EC_EXT_Qt5Quick_LIB_DIR ${EC_EXT_Qt5Quick_LIB_RELEASE} DIRECTORY)
   list(APPEND CMAKE_PREFIX_PATH "${EC_EXT_Qt5Quick_LIB_DIR}/cmake")
endif(EC_EXT_Qt5Quick_LIB_RELEASE)
if(EC_EXT_Qt5Quick_LIB)
   get_filename_component(EC_EXT_Qt5Quick_LIB_DIR ${EC_EXT_Qt5Quick_LIB} DIRECTORY)
   list(APPEND CMAKE_PREFIX_PATH "${EC_EXT_Qt5Quick_LIB_DIR}/cmake")
endif(EC_EXT_Qt5Quick_LIB)
if(osgQtQuick_WITH_QT_PRIVATE)
  find_package(Qt5Quick CONFIG REQUIRED
    COMPONENTS Private)
else()
  find_package(Qt5Quick CONFIG REQUIRED)
endif()

if(osgQtQuick_WITH_EARTH)
  find_package(OsgEarth 2.0 MODULE REQUIRED)
endif()

include(GNUInstallDirs)

if(OSGQTQUICK_ACTIN_BUILD AND NOT DEFINED CMAKE_INSTALL_QMLDIR)
   set(CMAKE_INSTALL_QMLDIR "bin/qml"
     CACHE STRING "qml modules")
endif(OSGQTQUICK_ACTIN_BUILD AND NOT DEFINED CMAKE_INSTALL_QMLDIR)

if(NOT DEFINED CMAKE_INSTALL_QMLDIR)
  if(NOT EXISTS "${QMAKE_EXECUTABLE}")
    get_target_property(QMAKE_EXECUTABLE Qt5::qmake LOCATION)
  endif()
  execute_process(COMMAND "${QMAKE_EXECUTABLE}" -query QT_INSTALL_PREFIX
    OUTPUT_VARIABLE QT_INSTALL_PREFIX)
  string(STRIP "${QT_INSTALL_PREFIX}" QT_INSTALL_PREFIX)
  execute_process(COMMAND "${QMAKE_EXECUTABLE}" -query QT_INSTALL_QML
    OUTPUT_VARIABLE QT_INSTALL_QML)
  string(STRIP "${QT_INSTALL_QML}" QT_INSTALL_QML)
  file(RELATIVE_PATH CMAKE_INSTALL_QMLDIR
    ${QT_INSTALL_PREFIX} ${QT_INSTALL_QML})
  set(CMAKE_INSTALL_QMLDIR "${CMAKE_INSTALL_QMLDIR}"
    CACHE STRING "qml modules")
endif()

include(osgQtQuickFunctions)

include_directories(
  "${CMAKE_BINARY_DIR}/include"
  ${OPENSCENEGRAPH_INCLUDE_DIRS}
  ${OSGEARTH_INCLUDE_DIRS}
  ${Qt5Qml_INCLUDE_DIRS}
  ${Qt5Quick_INCLUDE_DIRS})

add_subdirectory(qml)
add_subdirectory(quick)

if(osgQtQuick_BUILD_IMPORTS)
  add_subdirectory(imports)
endif()

if(osgQtQuick_BUILD_DEBUGGER)
  add_subdirectory(debugger)
endif()

install(EXPORT osgQtQuick
  DESTINATION "lib/cmake/osgQtQuick"
  FILE osgQtQuickTargets.cmake)

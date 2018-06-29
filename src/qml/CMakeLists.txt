if(DEFINED OSGQTQUICK_ACTIN_BUILD)
    ecProject(osgQtQml)
endif()

if(DYNAMIC_OSGQTQUICK)
    add_definitions(-DOSGQTQML_LIBRARY)
else()
    add_definitions(-DOSGQTQML_LIBRARY_STATIC)
endif()

set(_srcs)
set(_moc_hdrs)

macro(SRC_Node _library _class)
   string(TOLOWER ${_library} _library_l)
   string(TOLOWER ${_class} _class_l)
   file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include/${_library}")
   file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/${_library}/${_class}"
     CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp\"\n")
   install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
     DESTINATION "include/${_library}" RENAME "${_class}")
   install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
     DESTINATION "include/${_library}" RENAME "${_class}" COMPONENT ${PROJECT_NAME}-hdr)
   install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
     DESTINATION "include/${_library}" RENAME "${_class}" COMPONENT ${PROJECT_NAME}-lib)
   install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
     DESTINATION "include/${_library}" RENAME "${_class}" COMPONENT ${PROJECT_NAME}-src)
  list(APPEND _srcs "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.cpp")
  list(APPEND _moc_hdrs "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp")
endmacro(SRC_Node)


# Meta node
macro(META_Node _library _class)
  string(TOLOWER ${_library} _library_l)
  string(TOLOWER ${_class} _class_l)
  file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include/${_library}")
  file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/${_library}/${_class}QtQml"
    CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp\"\n")
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQml")
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQml" COMPONENT ${PROJECT_NAME}-hdr)
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQml" COMPONENT ${PROJECT_NAME}-lib)
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQml" COMPONENT ${PROJECT_NAME}-src)
  file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/${_library}/${_class}QtQmlIndex"
    CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}index.hpp\"\n")
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}index.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQmlIndex")
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}index.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQmlIndex" COMPONENT ${PROJECT_NAME}-hdr)
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}index.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQmlIndex" COMPONENT ${PROJECT_NAME}-lib)
  install(FILES "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}index.hpp"
    DESTINATION "include/${_library}" RENAME "${_class}QtQmlIndex" COMPONENT ${PROJECT_NAME}-src)
  list(APPEND _srcs "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.cpp")
  list(APPEND _moc_hdrs "${CMAKE_CURRENT_LIST_DIR}/${_library_l}/${_class_l}.hpp")
endmacro(META_Node)

META_Node(osg Object)
META_Node(osg Node)
META_Node(osg StateSet)
META_Node(osg Group)
META_Node(osg Geode)
META_Node(osg Shape)
META_Node(osg CompositeShape)
META_Node(osg Box)
META_Node(osg Sphere)
META_Node(osg Cylinder)
META_Node(osg Transform)
META_Node(osg MatrixTransform)
META_Node(osg PositionAttitudeTransform)
META_Node(osg Camera)
META_Node(osg Drawable)
META_Node(osg ShapeDrawable)
META_Node(osg GraphicsContext)
META_Node(osg Light)
META_Node(osg LightModel)
META_Node(osg LightSource)
META_Node(osg StateAttribute)



META_Node(osg Notify) # Custom type

META_Node(osgDB Loader) # Custom type

META_Node(osgGA CameraManipulator)
META_Node(osgGA StandardManipulator)
META_Node(osgGA FirstPersonManipulator)
META_Node(osgGA FlightManipulator)
META_Node(osgGA OrbitManipulator)
META_Node(osgGA NodeTrackerManipulator)
META_Node(osgGA TrackballManipulator)

META_Node(osgManipulator Dragger)
META_Node(osgManipulator RotateSphereDragger)
META_Node(osgManipulator CompositeDragger)
META_Node(osgManipulator TabPlaneDragger)
META_Node(osgManipulator TabBoxDragger)

META_Node(osgShadow ShadowedScene)
META_Node(osgShadow ShadowTechnique)
META_Node(osgShadow ShadowMap)


META_Node(osgText Style)
META_Node(osgText Font)
META_Node(osgText FontImplementation)
META_Node(osgText TextBase)
META_Node(osgText Text3D)

if(osgQtQuick_WITH_OSGQT)
  META_Node(osgQt QFontImplementation)
endif()

META_Node(osgViewer CompositeViewer)

SRC_Node(osg OsgQtConversion)

set(_hdrs
  object.hpp
  osg/object.hpp
  osg/node.hpp
  osg/notify.hpp
  osg/group.hpp
  osg/transform.hpp
  osg/positionattitudetransform.hpp
  osg/camera.hpp
  osg/drawable.hpp
  osg/shapedrawable.hpp
  osg/graphicscontext.hpp
  osg/light.hpp
  osg/lightsource.hpp
  osg/lightmodel.hpp
  osg/stateattribute.hpp

  osgdb/loader.hpp
  osgdb/loaderindex.hpp
  osgga/cameramanipulator.hpp
  osgga/trackballmanipulator.hpp
  osgviewer/compositeviewer.hpp
  ${_moc_hdrs})

list(APPEND _srcs
  index.cpp
  object.cpp
# osg
  osg/object.cpp
  osg/node.cpp
  osg/notify.cpp
  osg/group.cpp
  osg/transform.cpp
  osg/positionattitudetransform.cpp
  osg/camera.cpp
  osg/drawable.cpp
  osg/shapedrawable.cpp
  osg/graphicscontext.cpp
  osg/module.cpp
  osg/light.cpp
  osg/lightindex.cpp
  osg/lightsource.cpp
  osg/lightsourceindex.cpp
  osg/lightmodel.cpp
  osg/lightmodelindex.cpp
  osg/stateattribute.cpp
  osg/stateattributeindex.cpp
# osgDB
  osgdb/loader.cpp
  osgdb/module.cpp
# osgGA
  osgga/cameramanipulator.cpp
  osgga/trackballmanipulator.cpp
  osgga/module.cpp
# osgManipulator
  osgmanipulator/module.cpp
#osgShadow
  osgshadow/shadowedscene.cpp
  osgshadow/shadowedsceneindex.cpp
  osgshadow/shadowtechnique.cpp
  osgshadow/shadowtechniqueindex.cpp
  osgshadow/shadowmap.cpp
  osgshadow/shadowmapindex.cpp
  osgshadow/module.cpp
# osgText
  osgtext/module.cpp
# osgViewer
  osgviewer/compositeviewer.cpp
  osgviewer/module.cpp
)

if(osgQtQuick_WITH_OSGQT)
  list(APPEND _srcs
    # osgQt
    osgqt/module.cpp)
endif()

if(osgQtQuick_WITH_EARTH)
  list(APPEND _moc_hdrs
    # osgEarthUtil
    osgearthutil/earthmanipulator.hpp)
  list(APPEND _srcs
    # osgEarthUtil
    osgearthutil/module.cpp
    osgearthutil/earthmanipulator.cpp)
endif()

qt5_wrap_cpp(_mocs
  ${_hdrs}
  ${_moc_hdrs})

source_group(GeneratedFiles FILES ${_mocs})

add_library(osgQtQml ${OSGQTQUICK_USER_DEFINED_DYNAMIC_OR_STATIC}
  ${_hdrs}
  ${_srcs}
  ${_moc_hdrs}
  ${_mocs}
)

osgqtquick_library(osgQtQml)

target_link_libraries(osgQtQml
  ${OPENTHREADS_LIBRARIES}
  ${OSG_LIBRARIES}
  ${OSGDB_LIBRARIES}
  ${OSGGA_LIBRARIES}
  ${OSGMANIPULATOR_LIBRARIES}
  ${OSGTEXT_LIBRARIES}
  ${OSGVIEWER_LIBRARIES}
  ${OSGSHADOW_LIBRARIES}
  ${OSGEARTHUTIL_LIBRARY}
  Qt5::Gui
  Qt5::Qml)

if(osgQtQuick_WITH_OSGQT)
  target_link_libraries(osgQtQml ${OSGQT_LIBRARIES})
  target_compile_definitions(osgQtQml
    PUBLIC "OSGQTQUICK_WITH_OSGQT=1")
endif()

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include/osgQtQml")

file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgQtQml/Export"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/export.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/export.hpp"
  DESTINATION "include/osgQtQml" RENAME "Export")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/export.hpp"
  DESTINATION "include/osgQtQml" RENAME "Export" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/export.hpp"
  DESTINATION "include/osgQtQml" RENAME "Export" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/export.hpp"
  DESTINATION "include/osgQtQml" RENAME "Export" COMPONENT ${PROJECT_NAME}-src)

file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgQtQml/Index"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/index.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/index.hpp"
  DESTINATION "include/osgQtQml" RENAME "Index")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/index.hpp"
  DESTINATION "include/osgQtQml" RENAME "Index" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/index.hpp"
  DESTINATION "include/osgQtQml" RENAME "Index" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/index.hpp"
  DESTINATION "include/osgQtQml" RENAME "Index" COMPONENT ${PROJECT_NAME}-src)

file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgQtQml/Object"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/object.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/object.hpp"
  DESTINATION "include/osgQtQml" RENAME "Object")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/object.hpp"
  DESTINATION "include/osgQtQml" RENAME "Object" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/object.hpp"
  DESTINATION "include/osgQtQml" RENAME "Object" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/object.hpp"
  DESTINATION "include/osgQtQml" RENAME "Object" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osg/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osg/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osg/module.hpp"
  DESTINATION "include/osg" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osg/module.hpp"
  DESTINATION "include/osg" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osg/module.hpp"
  DESTINATION "include/osg" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osg/module.hpp"
  DESTINATION "include/osg" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgDB/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgdb/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgdb/module.hpp"
  DESTINATION "include/osgDB" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgdb/module.hpp"
  DESTINATION "include/osgDB" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgdb/module.hpp"
  DESTINATION "include/osgDB" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgdb/module.hpp"
  DESTINATION "include/osgDB" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgGA/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgga/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgga/module.hpp"
  DESTINATION "include/osgGA" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgga/module.hpp"
  DESTINATION "include/osgGA" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgga/module.hpp"
  DESTINATION "include/osgGA" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgga/module.hpp"
  DESTINATION "include/osgGA" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgManipulator/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgmanipulator/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgmanipulator/module.hpp"
  DESTINATION "include/osgManipulator" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgmanipulator/module.hpp"
  DESTINATION "include/osgManipulator" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgmanipulator/module.hpp"
  DESTINATION "include/osgManipulator" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgmanipulator/module.hpp"
  DESTINATION "include/osgManipulator" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)

file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgShadow/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgshadow/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgshadow/module.hpp"
  DESTINATION "include/osgShadow" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgshadow/module.hpp"
  DESTINATION "include/osgShadow" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgshadow/module.hpp"
  DESTINATION "include/osgShadow" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgshadow/module.hpp"
  DESTINATION "include/osgShadow" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgText/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgtext/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgtext/module.hpp"
  DESTINATION "include/osgText" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgtext/module.hpp"
  DESTINATION "include/osgText" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgtext/module.hpp"
  DESTINATION "include/osgText" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgtext/module.hpp"
  DESTINATION "include/osgText" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgQt/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgqt/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgqt/module.hpp"
  DESTINATION "include/osgQt" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgqt/module.hpp"
  DESTINATION "include/osgQt" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgqt/module.hpp"
  DESTINATION "include/osgQt" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgqt/module.hpp"
  DESTINATION "include/osgQt" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgViewer/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgviewer/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgviewer/module.hpp"
  DESTINATION "include/osgViewer" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgviewer/module.hpp"
  DESTINATION "include/osgViewer" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgviewer/module.hpp"
  DESTINATION "include/osgViewer" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgviewer/module.hpp"
  DESTINATION "include/osgViewer" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)


if(osgQtQuick_WITH_EARTH)

file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/include/osgEarthUtil/ModuleQtQml"
  CONTENT "#include \"${CMAKE_CURRENT_LIST_DIR}/osgearthutil/module.hpp\"\n")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgearthutil/module.hpp"
  DESTINATION "include/osgEarthUtil" RENAME "ModuleQtQml")
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgearthutil/module.hpp"
  DESTINATION "include/osgEarthUtil" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-hdr)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgearthutil/module.hpp"
  DESTINATION "include/osgEarthUtil" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-lib)
install(FILES "${CMAKE_CURRENT_LIST_DIR}/osgearthutil/module.hpp"
  DESTINATION "include/osgEarthUtil" RENAME "ModuleQtQml" COMPONENT ${PROJECT_NAME}-src)

META_Node(osgEarthUtil EarthManipulator)

endif() # osgQtQuick_WITH_EARTH

set_target_properties(osgQtQml PROPERTIES
  INTERFACE_LINK_LIBRARIES "")

install(TARGETS osgQtQml EXPORT osgQtQuick
  RUNTIME DESTINATION "bin"
  ARCHIVE DESTINATION "lib"
  LIBRARY DESTINATION "lib")

if(DEFINED OSGQTQUICK_ACTIN_BUILD)
   ecPackageLibrary(osgQtQml osgQtQml)
endif()


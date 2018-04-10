# Library configuration
function(osgqtquick_library library_name)
  set(target_name ${library_name})
  set_target_properties(${target_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
  if(osgQtQuick_WITH_QT_PRIVATE)
    set_property(TARGET ${target_name} APPEND PROPERTY
      COMPILE_DEFINITIONS "OSGQTQUICK_WITH_QT_PRIVATE=1")
  endif()
endfunction()

# Executable configuration
function(osgqtquick_executable executable_name)
  set(target_name ${executable_name})
  set_target_properties(${target_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endfunction()

# Imported module configuration
function(osgqtquick_imported_module module_name)

  string(TOLOWER ${module_name} module_name_lower)

  set(target_name ${module_name_lower}plugin)

  set(module_src_dir ${osgQtQuick_ROOT_DIR}/src/imports/${module_name_lower})

  qt5_generate_moc("${module_src_dir}/plugin.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/plugin.moc")

  add_library(${target_name} MODULE
    "${module_src_dir}/plugin.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/plugin.moc")

  set_property(TARGET ${target_name} PROPERTY
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}")

  if(OSGQTQUICK_ACTIN_BUILD)
    set_target_properties(${target_name} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}"
      LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}"
      RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}"
      LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}"
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}"
      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}")
  endif(OSGQTQUICK_ACTIN_BUILD)

  if(MINGW)
    set_target_properties(${target_name} PROPERTIES PREFIX "")
  endif()

  target_include_directories(${target_name}
    PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")

  target_compile_definitions(${target_name}
    PRIVATE QT_PLUGIN $<$<CONFIG:Release>:QT_NO_DEBUG>)

  target_link_libraries(${target_name} osgQtQuick Qt5::Quick)

  file(WRITE "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}/qmldir"
    "module ${module_name}\nplugin ${target_name}\n")

  install(FILES
    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}/qmldir"
    DESTINATION "${CMAKE_INSTALL_QMLDIR}/${module_name}")
  install(FILES
    "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_QMLDIR}/${module_name}/qmldir"
    DESTINATION "${CMAKE_INSTALL_QMLDIR}/${module_name}" COMPONENT ${PROJECT_NAME}-rt)

  install(TARGETS ${target_name}
    LIBRARY DESTINATION "${CMAKE_INSTALL_QMLDIR}/${module_name}")
  install(TARGETS ${target_name}
    LIBRARY DESTINATION "${CMAKE_INSTALL_QMLDIR}/${module_name}" COMPONENT ${PROJECT_NAME}-rt)

endfunction()

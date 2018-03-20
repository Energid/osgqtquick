# Get the directory where this config file resides
ecGetScriptDir(inst)

if (NOT EC_EMBEDDED)
    ecBundle(render_OSS)
endif (NOT EC_EMBEDDED)

if(";${EC_REPOSITORIES};" MATCHES ";osgqtquick;")
   set(OSGQTQUICK_ACTIN_BUILD TRUE INTERNAL)
endif(";${EC_REPOSITORIES};" MATCHES ";osgqtquick;")

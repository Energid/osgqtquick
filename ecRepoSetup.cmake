# Get the directory where this config file resides
ecGetScriptDir(inst)

# We assume that osgqtquick repository is being built only for non-embedded builds
ecBundle(render_OSS)

if(";${EC_REPOSITORIES};" MATCHES ";osgqtquick;")
   set(OSGQTQUICK_ACTIN_BUILD TRUE CACHE INTERNAL "Flag indicating whether OsgQtQuick is being built as Actin dependency")
endif(";${EC_REPOSITORIES};" MATCHES ";osgqtquick;")

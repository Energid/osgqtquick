# Get the directory where this config file resides
ecGetScriptDir(inst)

# We assume that osgqtquick repository is being built only for non-embedded builds
ecBundle(render_OSS)
set(OSGQTQUICK_ACTIN_BUILD TRUE CACHE INTERNAL "Flag indicating whether OsgQtQuick is being built as Actin dependency")
ecPackageFiles(osgqtquick-rt LICENSE)
ecPackageFiles(osgqtquick-lib LICENSE)
ecPackageFiles(osgqtquick-src LICENSE)

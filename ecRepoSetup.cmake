# Get the directory where this config file resides
ecGetScriptDir(inst)

if (NOT EC_EMBEDDED)
    ecBundle(render_OSS)
endif (NOT EC_EMBEDDED)

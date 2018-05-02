#include "module.hpp"

#include "shadowedscene.hpp"
#include "shadowtechnique.hpp"
#include "shadowmap.hpp"

#include <osgQtQuick/Version>
#include <QtQml/QtQml>

#include <QtCore/QDebug>

namespace osgShadow {

void registerQtQmlTypes(const char *uri)


{

    qmlRegisterType<ShadowedSceneQtQml>(
                uri, osgQtQuick_VERSION_MAJOR, osgQtQuick_VERSION_MINOR,
                "ShadowedScene");

    qmlRegisterType<ShadowMapQtQml>(
                uri, osgQtQuick_VERSION_MAJOR, osgQtQuick_VERSION_MINOR,
                "ShadowMap");

    qmlRegisterUncreatableType<ShadowTechniqueQtQml>(
                uri, osgQtQuick_VERSION_MAJOR, osgQtQuick_VERSION_MINOR,
                "ShadowTechnique", "[osgQtQuick] ShadowTechnique is Uncreatable");



}

}

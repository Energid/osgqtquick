#include "module.hpp"

#include "textbaseindex.hpp"
#include "text3dindex.hpp"

#include <osgQtQuick/Version>
#include <QtQml>

#include <QDebug>

namespace osgText {

void regisgerQtQmlTypes(const char *uri)
{
    qmlRegisterUncreatableType<TextBaseQtQml>(
                uri, osgQtQuick_VERSION_MAJOR, osgQtQuick_VERSION_MINOR,
                "TextBase", "[osgQtQuick] TextBase is Uncreatable");

    qmlRegisterType<Text3DQtQml>(
                uri, osgQtQuick_VERSION_MAJOR, osgQtQuick_VERSION_MINOR,
                "Text3D");
}

}

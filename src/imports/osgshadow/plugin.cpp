#include <QtQml/QtQml>

#include <osgShadow/ModuleQtQml>

class osgShadowPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri)
    {
        Q_ASSERT(uri == QLatin1String("osgShadow"));
        // osgShadow types from osgQtQml library
        osgShadow::registerQtQmlTypes(uri);
    }
};

#include "plugin.moc"

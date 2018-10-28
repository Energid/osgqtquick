#ifndef _OSGVIEWER_VIEW_QTQUICK_
#define _OSGVIEWER_VIEW_QTQUICK_ 1

#include <osgQtQuick/Object>

#include <osg/CameraQtQml>
#include <osgGA/CameraManipulatorQtQml>

namespace osg {
   class Operation;
}

namespace osgViewer {

class View;

class OSGQTQUICK_EXPORT ViewQtQuick : public osgQtQuick::Object
{
  Q_OBJECT

  Q_PROPERTY(osg::NodeQtQml* sceneData READ getSceneData WRITE setSceneData NOTIFY sceneDataChanged)
  Q_PROPERTY(osg::CameraQtQml* camera READ getCamera WRITE setCamera NOTIFY cameraChanged)
  Q_PROPERTY(osgGA::CameraManipulatorQtQml* cameraManipulator READ getCameraManipulator WRITE setCameraManipulator NOTIFY cameraManipulatorChanged)

public:
  class Index;

  Q_INVOKABLE osg::NodeQtQml* getSceneData();
  Q_INVOKABLE void setSceneData(osg::NodeQtQml *node);

  Q_INVOKABLE osg::CameraQtQml* getCamera();
  Q_INVOKABLE void setCamera(osg::CameraQtQml *camera);

  Q_INVOKABLE osgGA::CameraManipulatorQtQml* getCameraManipulator();
  Q_INVOKABLE void setCameraManipulator(osgGA::CameraManipulatorQtQml *manipulator);

  void addUpdateOperation(osg::Operation* pOperation);

  ViewQtQuick(QQuickItem *parent = 0);
  ViewQtQuick(Index *index, QQuickItem *parent = 0);

  void classBegin() override;

  static ViewQtQuick* fromView(View *view, QQuickItem *parent = 0);

Q_SIGNALS:
  void sceneDataChanged(osg::NodeQtQml *node);
  void cameraChanged(osg::CameraQtQml *camera);
  void cameraManipulatorChanged(osgGA::CameraManipulatorQtQml *manipulator);

protected:
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void mouseDoubleClickEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;

  void geometryChanged(const QRectF & newGeometry, const QRectF & oldGeometry) override;

  QSGNode* updatePaintNode(QSGNode *oldNode,
                           QQuickItem::UpdatePaintNodeData *updatePaintNodeData) override;

  void itemChange(ItemChange change, const ItemChangeData & value) override;
};

}

#endif // _OSGVIEWER_VIEW_QTQUICK_

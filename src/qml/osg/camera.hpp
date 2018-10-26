#ifndef _OSG_CAMERA_QTQML_
#define _OSG_CAMERA_QTQML_ 1

#include <osg/TransformQtQml>

#include <QtGui/QColor>

namespace osg {

class Camera;

class OSGQTQML_EXPORT CameraQtQml : public TransformQtQml
{
  Q_OBJECT

  Q_PROPERTY(QColor clearColor READ getClearColor WRITE setClearColor NOTIFY clearColorChanged)
  Q_PROPERTY(double nearFarRatio READ getNearFarRatio WRITE setNearFarRatio NOTIFY nearFarRatioChanged)
   /// \property cullMask Cull Mask for the Camera Node.
   Q_PROPERTY(quint32 cullMask READ cullMask WRITE setCullMask NOTIFY cullMaskChanged)
   /// \property Node Mask for the Camera Node.
   Q_PROPERTY(quint32 nodeMask READ nodeMask WRITE setNodeMask NOTIFY nodeMaskChanged)

public:
  class Index;

  CameraQtQml(QObject *parent = 0);
  CameraQtQml(Index *, QObject *parent = 0);

  void classBegin() override;

  Q_INVOKABLE QColor getClearColor() const;
  Q_INVOKABLE void setClearColor(const QColor &color);

  Q_INVOKABLE double getNearFarRatio() const;
  Q_INVOKABLE void setNearFarRatio(const double ratio);

  ///
  /// \brief Getter for cullMask property.
  /// \return Cull Mask value
  ///
  Q_INVOKABLE const quint32 cullMask
     (
     ) const;

  ///
  /// \brief Getter for nodeMask property
  /// \return Node Mask value
  ///
  Q_INVOKABLE const quint32 nodeMask
     (
     ) const;

  ///
  /// \brief Setter for cullMask property.
  /// \param mask Value of Cull Mask to set.
  ///
  Q_INVOKABLE void setCullMask
     (
     const quint32 mask
     );

  ///
  /// \brief Setter for nodeMask property.
  /// \param mask Value of Node Mask to set.
  ///
  Q_INVOKABLE void setNodeMask
     (
     const quint32 mask
     );

  Camera* camera();

  static CameraQtQml* fromCamera(Camera *camera, QObject *parent = 0);

Q_SIGNALS:
  ///
  /// \brief Signal emitted when cull mask is changed via this object
  /// \param mask New value of the cull mask.
  ///
  void cullMaskChanged
     (
     quint32 mask
     );

  ///
  /// \brief Signal emitted when the node mask is changed via this object.
  /// \param mask New value of the node mask.
  ///
  void nodeMaskChanged
     (
     quint32 mask
     );

  void clearColorChanged(const QColor &color) const;
  void nearFarRatioChanged(const double ratio) const;
};

}

#endif // _OSG_CAMERA_QTQML_

#ifndef _OSG_DRAWABLE_QTQML_
#define _OSG_DRAWABLE_QTQML_ 1

#include <osg/NodeQtQml>

namespace osg {

class Drawable;

class OSGQTQML_EXPORT DrawableQtQml : public osg::NodeQtQml
{
  Q_OBJECT

public:
  class Index;

  DrawableQtQml(QObject *parent = 0);
  DrawableQtQml(Index *index, QObject *parent = 0);

  void classBegin() override;

  Drawable* drawable();

  static DrawableQtQml* fromDrawable(Drawable *drawable, QObject *parent = 0);
};

}

#endif // _OSG_DRAWABLE_QTQML_

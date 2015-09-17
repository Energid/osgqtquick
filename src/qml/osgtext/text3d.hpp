#ifndef _OSGTEXT_TEXT3D_QTQML_
#define _OSGTEXT_TEXT3D_QTQML_ 1

#include <osgText/TextBaseQtQml>

#include <QColor>

namespace osgText {

class Text3D;

class OSGQTQML_EXPORT Text3DQtQml : public TextBaseQtQml
{
  Q_OBJECT

public:
  class Index;

  Text3DQtQml(QObject *parent = 0);
  Text3DQtQml(Index *, QObject *parent = 0);

  void classBegin();

  Text3D* text3D();

  static Text3DQtQml* fromText3D(Text3D *text3D, QObject *parent = 0);

signals:

};

}

#endif // _OSGTEXT_TEXT3D_QTQML_

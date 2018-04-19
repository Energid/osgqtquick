#ifndef _OSG_STATESET_QTQML_
#define _OSG_STATESET_QTQML_ 1

#include <osg/ObjectQtQml>

namespace osg {

class StateSet;
class StateAttributeQtQml;

class OSGQTQML_EXPORT StateSetQtQml : public osg::ObjectQtQml
{
  Q_OBJECT

public:
  class Index;

  StateSetQtQml(QObject *parent = 0);
  StateSetQtQml(Index *index, QObject *parent = 0);

  void classBegin();

  Q_INVOKABLE void setGlobalDefaults();

  Q_INVOKABLE void setMode(unsigned int mode, unsigned int modeValue);
  Q_INVOKABLE void setTextureMode(unsigned int unit, unsigned int mode, unsigned int modeValue);
  Q_INVOKABLE void setAttributeAndModes(osg::StateAttributeQtQml *pAttribute, unsigned int modeValue);


  StateSet* stateSet();

  static StateSetQtQml* fromStateSet(StateSet *stateSet, QObject *parent = 0);
};

}

#endif // _OSG_STATESET_QTQML_

//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file stateattribute.hpp
/// @class StateAttributeQtQml
//
//------------------------------------------------------------------------------
#ifndef StateAttributeQtQml_H
#define StateAttributeQtQml_H




#include <osg/ObjectQtQml>

#include <osg/StateAttribute>

#include <QtGui/QVector4D>
#include <QtGui/QVector3D>

namespace osg {

///
/// \brief The StateAttributeQtQml class extends the StateAttributeQtQml item/class provided by the
/// OsgQtQuick framework.
///
/// \details It wraps an instance of osg::StateAttribute and exposes necessary API from it in QML.
///
/// \qmltype{StateAttributeQtQml}
/// \ingroup
class OSGQTQML_EXPORT StateAttributeQtQml :
    public osg::ObjectQtQml
{
   Q_OBJECT


public:
   class Index;

   ///
   /// \brief StateAttributeQtQml default constructor
   /// \param parent Parent QObject/Item
   ///
   explicit StateAttributeQtQml
      (
      QObject *parent = 0
      );

   osg::StateAttribute* StateAttribute
      (
      );


   ///
   /// \brief StateAttributeQtQml constructor
   /// \param index Initial StateAttributeQtQml index (Object mapping between OSG and QML types for Camera).
   /// \param parent Parent QObject/Item.
   ///
   StateAttributeQtQml
      (
      StateAttributeQtQml::Index *index,
      QObject *parent = 0
      );



public Q_SLOTS:


};


}

#endif // StateAttributeQtQml_H

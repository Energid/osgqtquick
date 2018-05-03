//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightsource.hpp
/// @class LightSourceQtQml
//
//------------------------------------------------------------------------------
#ifndef LightSourceQtQml_H
#define LightSourceQtQml_H


#include <osg/GroupQtQml>

#include <QtGui/QVector4D>
#include <QtGui/QVector3D>
#include <QtCore/QVariant>



namespace osg {

class LightQtQml;
class LightSource;

///
/// \brief The LightSourceQtQml class wraps the osg::LightSource item/class provided by the
/// Osg framework.
///
/// \details It wraps an instance of osg::LightSource and exposes necessary API from it in QML.
///
/// \qmltype{LightSourceQtQml}
/// \ingroup
class OSGQTQML_EXPORT LightSourceQtQml :
    public osg::GroupQtQml
{
   Q_OBJECT

   /// \property light.
   ///
   /// \details
   Q_PROPERTY(QVariant light READ light WRITE setLight NOTIFY lightChanged)

   /// \property localStateSetModes for the Light Source.
   ///
   /// \details
   Q_PROPERTY(unsigned int localStateSetModes READ localStateSetModes WRITE setLocalStateSetModes NOTIFY localStateSetModesChanged)


public:
   class Index;

   ///
   /// \brief LightSourceQtQml default constructor
   /// \param parent Parent QObject/Item
   ///
   explicit LightSourceQtQml
      (
      QObject *parent = 0
      );

   void classBegin
      (
      );

   ///
   /// \brief LightSourceQtQml constructor
   /// \param index Initial LightSourceQtQml index (Object mapping between OSG and QML types for Camera).
   /// \param parent Parent QObject/Item.
   ///
   LightSourceQtQml
      (
      LightSourceQtQml::Index *index,
      QObject *parent = 0
      );

   osg::LightSource* lightSource
      (
      );

   ///
   /// \brief light Getter for light property
   /// \return  value
   ///
   const QVariant light
      (
      ) const;

   ///
   /// \brief localStateSetModes Getter for localStateSetModes property
   /// \return  value
   ///
   const unsigned int localStateSetModes
      (
      ) const;


   Q_INVOKABLE void setStateSetModes(StateSetQtQml* stateSet, unsigned int mode);


public Q_SLOTS:
   ///
   /// \brief setLight Setter for light property.
   /// \param num Value of light to set.
   ///
   void setLight
      (
      const QVariant obj
      );

   ///
   /// \brief setLight Setter for light property.
   /// \param num Value of light to set.
   ///
   void setLocalStateSetModes
      (
      const unsigned int mode
      );


Q_SIGNALS:
   ///lightChanged
   /// \brief lightChanged Signal emitted when the light is changed via this object.
   /// \param num for  lightNum.
   ///
   void lightChanged
      (
      QVariant obj
      );

   ///localStateSetModesChanged
   /// \brief localStateSetModesChanged Signal emitted when the localStateSetModesChanged is changed via this object.
   /// \param num for  lightNum.
   ///
   void localStateSetModesChanged
      (
      const int mode
      );


protected:

   osg::LightQtQml*   m_pLightObject;
   int       m_LocalStateSetModes;

};

}


#endif // LightSourceQtQml_H

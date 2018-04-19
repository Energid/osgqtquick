//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightmodel.h
/// @class LightModelQtQml
//
//------------------------------------------------------------------------------
#ifndef LightModelQtQml_H
#define LightModelQtQml_H

#include "stateattribute.hpp"

#include <osg/LightModel>

#include <QtGui/QVector4D>
#include <QtGui/QVector3D>

///
/// \brief The LightModelQtQml class extends or wraps the LightModel item/class provided by the
/// Osg framework.
///
/// \details It wraps an instance of osg::LightModel and exposes necessary API from it in QML.
///
/// \qmltype{LightModelQtQml}
/// \ingroup
class OSGQTQML_EXPORT LightModelQtQml :
    public StateAttributeQtQml
{
   Q_OBJECT

   /// \property ambientIntensity for the LightModel.
   ///
   /// \details
   Q_PROPERTY(QVector4D ambientIntensity READ ambientIntensity WRITE setAmbientIntensity NOTIFY ambientIntensityChanged)

   /// \property twoSided for the LightModel.
   ///
   /// \details
   Q_PROPERTY(bool twoSided READ twoSided WRITE setTwoSided NOTIFY twoSidedChanged)

   /// \property localViewer for the LightModel.
   ///
   /// \details
   Q_PROPERTY(bool localViewer READ localViewer WRITE setLocalViewer NOTIFY localViewerChanged)


public:
   class Index;

   ///
   /// \brief LightModelQtQml default constructor
   /// \param parent Parent QObject/Item
   ///
   explicit LightModelQtQml
      (
      QObject *parent = 0
      );



   void classBegin
      (
      );

   ///
   /// \brief LightModelQtQml constructor
   /// \param index Initial LightModelQtQml index (Object mapping between OSG and QML types for Camera).
   /// \param parent Parent QObject/Item.
   ///
   LightModelQtQml
      (
      LightModelQtQml::Index *index,
      QObject *parent = 0
      );

   ///
   /// \brief ambientIntensity Getter for ambientIntensity property
   /// \return  value
   ///
   const QVector4D ambientIntensity
      (
      )const;

   ///
   /// \brief twoSided Getter for twoSided property
   /// \return  value
   ///
   const bool twoSided
      (
      )const;

   ///
   /// \brief localViewer Getter for localViewer property
   /// \return  value
   ///
   const bool localViewer
      (
      )const;


public Q_SLOTS:

   ///
   /// \brief ambientIntensity setter for ambientIntensity property
   /// \sets the vect as ambientIntensity for the light
   ///
   void setAmbientIntensity
      (
      const QVector4D vect
      );

   ///
   /// \brief twoSided setter for twoSided property
   /// \sets the flag as twoSided for the light
   ///
   void setTwoSided
      (
      const bool flag
      );

   ///
   /// \brief localViewer setter for localViewer property
   /// \sets the flag as localViewer for the light
   ///
   void setLocalViewer
      (
      const bool flag
      );


Q_SIGNALS:
   ///
   /// \brief ambientIntensityChangedSignal emitted when the ambientIntensity property is changed via this object.
   /// \param for ambient
   ///
   void ambientIntensityChanged
      (
      const QVector4D vect
      );

   ///
   /// \brief twoSidedChangedSignal emitted when the twoSided property is changed via this object.
   /// \param for
   ///
   void twoSidedChanged
      (
      const bool flag
      );

   ///
   /// \brief localViewerChangedSignal emitted when the localViewer property is changed via this object.
   /// \param for
   ///
   void localViewerChanged
      (
      const bool flag
      );

};




#endif // LightModelQtQml_H

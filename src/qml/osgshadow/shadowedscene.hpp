//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file LightQtQml.hpp
/// @class LightQtQml
//
//------------------------------------------------------------------------------
#ifndef ShadowedSceneQtQml_H
#define ShadowedSceneQtQml_H

#include "shadowtechnique.hpp"
#include <osg/GroupQtQml>
#include <osgShadow/ShadowedScene>

#include <QtGui/QVector4D>
#include <QtGui/QVector3D>

namespace osgShadow {
///
/// \brief The ShadowedSceneQtQml class wraps the ShadowedScene item/class provided by the
/// Osg framework.
///
/// \details It wraps an instance of osgShadow::ShadowedScene and exposes necessary API from it in QML.
///
/// \qmltype{ShadowedSceneQtQml}
/// \ingroup
class OSGQTQML_EXPORT ShadowedSceneQtQml :
    public osg::GroupQtQml
{
   Q_OBJECT

   /// \property receivesShadowTraversalMask.
   ///
   /// \details
   Q_PROPERTY(int receivesShadowTraversalMask READ receivesShadowTraversalMask
              WRITE setReceivesShadowTraversalMask NOTIFY receivesShadowTraversalMaskChanged)

   /// \property castsShadowTraversalMask.
   ///
   /// \details
   Q_PROPERTY(int castsShadowTraversalMask READ castsShadowTraversalMask
               WRITE setCastsShadowTraversalMask NOTIFY castsShadowTraversalMaskChanged)




public:
   class Index;

   ///
   /// \brief LightQtQml default constructor
   /// \param parent Parent QObject/Item
   ///
   explicit ShadowedSceneQtQml
      (
      QObject *parent = 0
      );

   osgShadow::ShadowedScene* shadowedScene
      (
      );

   static ShadowedSceneQtQml* fromShadowedScene
      (
      osgShadow::ShadowedScene *pLight,
      QObject *pParent = 0
      );

   void classBegin
      (
      );

   ///
   /// \brief LightQtQml constructor
   /// \param index Initial LightQtQml index (Object mapping between OSG and QML types for Camera).
   /// \param parent Parent QObject/Item.
   ///
   ShadowedSceneQtQml
      (
      ShadowedSceneQtQml::Index *index,
      QObject *parent = 0
      );

   Q_INVOKABLE osg::StateSetQtQml* getOrCreateStateSet
      (
      );

   Q_INVOKABLE void setShadowTechnique(ShadowTechniqueQtQml* technique);

   ///
   /// \brief castsShadowTraversalMask Getter for castsShadowTraversalMask property
   /// \return  value
   ///
   unsigned int castsShadowTraversalMask
      (
      ) const;

   ///
   /// \brief receivesShadowTraversalMask Getter for receivesShadowTraversalMask property
   /// \return  value
   ///
   unsigned int receivesShadowTraversalMask
      (
      ) const;



public Q_SLOTS:

   void setCastsShadowTraversalMask
      (
      unsigned int mask
      );
   void setReceivesShadowTraversalMask
      (
      unsigned int mask
      );




Q_SIGNALS:
   void castsShadowTraversalMaskChanged
      (
      unsigned int
      );

   void receivesShadowTraversalMaskChanged
      (
      unsigned int
      );


};

}


#endif // ShadowedSceneQtQml_H

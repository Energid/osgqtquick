//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file ShadowMapQtQml.hpp
/// @class ShadowMapQtQml
//
//------------------------------------------------------------------------------
#ifndef ShadowMapQtQml_H
#define ShadowMapQtQml_H

#include "shadowtechnique.hpp"

#include <osg/Object>
#include <osg/LightQtQml>
#include <osg/LightSourceQtQml>

#include <QtGui/QVector2D>
#include <QtGui/QVector4D>
#include <QtGui/QVector3D>

namespace osgShadow {
///
/// \brief The ShadowMapQtQml class wraps the ShadowMap item/class provided by the
/// Osg framework.
///
/// \details It wraps an instance of osgShadow::ShadowMap and exposes necessary API from it in QML.
///
/// \qmltype{ShadowMapQtQml}
/// \ingroup
class OSGQTQML_EXPORT ShadowMapQtQml :
    public ShadowTechniqueQtQml
{
   Q_OBJECT

   /// \property textureUnit for the shadow map.
   ///
   /// \details
   Q_PROPERTY(unsigned int textureUnit READ textureUnit WRITE setTextureUnit NOTIFY textureUnitChanged)

   /// \property textureUnit for the shadow map.
   ///
   /// \details
   Q_PROPERTY(QVector2D polygonOffset READ polygonOffset WRITE setPolygonOffset NOTIFY polygonOffsetChanged)


    /// \property ambientBias for the shadow map.
    ///
    /// \details
    Q_PROPERTY(QVector2D ambientBias READ ambientBias WRITE setAmbientBias NOTIFY ambientBiasChanged)

    /// \property textureSize for the shadow map.
    ///
    /// \details
    Q_PROPERTY(QVector2D textureSize READ textureSize WRITE setTextureSize NOTIFY textureSizeChanged)



public:
    class Index;

    ///
    /// \brief LightQtQml default constructor
    /// \param parent Parent QObject/Item
    ///
    explicit ShadowMapQtQml
       (
       QObject *parent = 0
       );

    ///
    /// \brief ShadowMapQtQml constructor
    /// \param index Initial ShadowMapQtQml index (Object mapping between OSG and QML types for Camera).
    /// \param parent Parent QObject/Item.
    ///
    ShadowMapQtQml
       (
       ShadowMapQtQml::Index *index,
       QObject *parent = 0
       );

    void classBegin
       (
       );

   ///
   /// \brief textureUnit Getter for textureUnit property
   /// \return  value
   ///
   unsigned int textureUnit
      (
      )const;

   ///
   /// \brief polygonOffset Getter for polygonOffset property
   /// \return  value
   ///
   QVector2D polygonOffset
      (
      )const;

   ///
   /// \brief ambientBias Getter for ambientBias property
   /// \return  value
   ///
   QVector2D ambientBias
      (
      )const;

   ///
   /// \brief textureSize Getter for textureSize property
   /// \return  value
   ///
   QVector2D textureSize
      (
      )const;

   /// Set the Light that will cast shadows
   Q_INVOKABLE void setLight(osg::LightQtQml* pLight);

   /// Set the Light Source that will cast shadows
   Q_INVOKABLE void setLight(osg::LightSourceQtQml* pLightSrc);

public Q_SLOTS:
   ///
   /// \brief setTextureUnit Setter for textureUnit property.
   /// \param unit Value of textureUnit to set.
   ///
   void setTextureUnit
      (
      unsigned int unit
      );

   ///
   /// \brief setPolygonOffset Setter for polygonOffset property.
   /// \param unit Value of polygonOffset to set.
   ///
   void setPolygonOffset
      (
      QVector2D offsetVect
      );

   ///
   /// \brief setAmbientBias Setter for ambientBias property.
   /// \param unit Value of ambientBias to set.
   ///
   void setAmbientBias
      (
      QVector2D ambientBiasVect
      );

   ///
   /// \brief setTextureSize Setter for textureSize property.
   /// \param unit Value of textureSize to set.
   ///
   void setTextureSize
      (
      QVector2D textureSizeVect
      );

Q_SIGNALS:
   void textureUnitChanged
      (
      unsigned int unit
      );

   void polygonOffsetChanged
      (
      QVector2D offsetVect
      );

   void ambientBiasChanged
      (
      QVector2D ambientBiasVect
      );

   void textureSizeChanged
      (
      QVector2D textureSizeVect
      );

};

}


#endif // ShadowMapQtQml_H

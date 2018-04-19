//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file LightQtQml.hpp
/// @class LightQtQml
//
//------------------------------------------------------------------------------
#ifndef LightQtQml_H
#define LightQtQml_H

#include "stateattribute.hpp"

#include <osg/Light>

#include <QtGui/QVector4D>
#include <QtGui/QVector3D>

///
/// \brief The LightQtQml class wraps the Light item/class provided by the
/// Osg framework.
///
/// \details It wraps an instance of osg::Light and exposes necessary API from it in QML.
///
/// \qmltype{LightQtQml}
/// \ingroup
class OSGQTQML_EXPORT LightQtQml :
    public StateAttributeQtQml
{
   Q_OBJECT

   /// \property lightNum for the Light.
   ///
   /// \details
   Q_PROPERTY(int lightNum READ lightNum WRITE setLightNum NOTIFY lightNumChanged)

   /// \property ambient for the Light.
   ///
   /// \details
   Q_PROPERTY(QVector4D ambient READ ambient WRITE setAmbient NOTIFY ambientChanged)

   /// \property diffuse for the Light.
   ///
   /// \details
   Q_PROPERTY(QVector4D diffuse READ diffuse WRITE setDiffuse NOTIFY diffuseChanged)

   /// \property specular for the Light.
   ///
   /// \details
   Q_PROPERTY(QVector4D specular READ specular WRITE setSpecular NOTIFY specularChanged)

   /// \property position for the Light.
   ///
   /// \details
   Q_PROPERTY(QVector4D position READ position WRITE setPosition NOTIFY positionChanged)

   /// \property direction for the Light.
   ///
   /// \details
   Q_PROPERTY(QVector3D direction READ direction WRITE setDirection NOTIFY directionChanged)


   /// \property constAttenuation for the Light.
   ///
   /// \details
   Q_PROPERTY(double constAttenuation READ constAttenuation WRITE setConstAttenuation NOTIFY constAttenuationChanged)

   /// \property linearAttenuation for the Light.
   ///
   /// \details
   Q_PROPERTY(double linearAttenuation READ linearAttenuation WRITE setLinearAttenuation NOTIFY linearAttenuationChanged)


   /// \property quadAttenuation for the Light.
   ///
   /// \details
   Q_PROPERTY(double quadAttenuation READ quadAttenuation WRITE setQuadAttenuation NOTIFY quadAttenuationChanged)


   /// \property spot exponent for the Light.
   ///
   /// \details
   Q_PROPERTY(double spotExponent READ spotExponent WRITE setSpotExponent NOTIFY spotExponentChanged)

   /// \property spotCutoff for the Light.
   ///
   /// \details
   Q_PROPERTY(double spotCutoff READ spotCutoff WRITE setSpotCutoff NOTIFY spotCutoffChanged)


public:
   class Index;

   ///
   /// \brief LightQtQml default constructor
   /// \param parent Parent QObject/Item
   ///
   explicit LightQtQml
      (
      QObject *parent = 0
      );

   osg::Light* light
      (
      );

   static LightQtQml* fromLight
      (
      osg::Light *pLight,
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
   LightQtQml
      (
      LightQtQml::Index *index,
      QObject *parent = 0
      );

   ///
   /// \brief lightNum Getter for lightNum property
   /// \return  value
   ///
   const int lightNum
      (
      ) const;

   ///
   /// \brief ambient Getter for ambient property
   /// \return  value
   ///
   const QVector4D ambient
      (
      )const;

   ///
   /// \brief diffuse Getter for diffuse property
   /// \return  value
   ///
   const QVector4D diffuse
      (
      )const;

   ///
   /// \brief specular Getter for specular property
   /// \return  value
   ///
   const QVector4D specular
      (
      )const;

   ///
   /// \brief position Getter for position property
   /// \return  value
   ///
   const QVector4D position
      (
      )const;

   ///
   /// \brief direction Getter for direction property
   /// \return  value
   ///
   const QVector3D direction
      (
      )const;

   ///
   /// \brief constAttenuation Getter for constant attenuation property
   /// \return  value
   ///
   const double constAttenuation
      (
      )const;

   ///
   /// \brief linearAttenuation Getter for linear attenuation property
   /// \return  value
   ///
   const double linearAttenuation
      (
      )const;

   ///
   /// \brief quadAttenuation Getter for quadradic attenuation property
   /// \return  value
   ///
   const double quadAttenuation
      (
      )const;

   ///
   /// \brief spotExponent Getter for  spotExponent property
   /// \return  value
   ///
   const double spotExponent
      (
      )const;

   ///
   /// \brief spotCutoff Getter for spotCutoff  property
   /// \return  value
   ///
   const double spotCutoff
      (
      )const;

public Q_SLOTS:
   ///
   /// \brief setLightNum Setter for lightNum property.
   /// \param num Value of lightNum to set.
   ///
   void setLightNum
      (
      const int num
      );


   ///
   /// \brief ambient setter for ambient property
   /// \sets the vect as ambient for the light
   ///
   void setAmbient
      (
      const QVector4D vect
      );

   ///
   /// \brief diffuse setter for diffuse property
   /// \sets the vect as diffuse for the light
   ///
   void setDiffuse
      (
      const QVector4D vect
      );

   ///
   /// \brief specular setter for specular property
   /// \sets the vect as specular for the light
   ///
   void setSpecular
      (
      const QVector4D vect
      );

   ///
   /// \brief position setter for position property
   /// \sets the vect as position for the light
   ///
   void setPosition
      (
      const QVector4D vect
      );

   ///
   /// \brief direction setter for direction property
   /// \sets the vect as direction for the light
   ///
   void setDirection
      (
      const QVector3D vect
      );


   ///
   /// \brief setConstAttenuation Setter for constAttenuation property.
   /// \param sets num to constant attenuation
   ///
   void setConstAttenuation
      (
      const double num
      );

   ///
   /// \brief setLinearAttenuation Setter for linearAttenuation property.
   /// \param sets num to linear attenuation
   ///
   void setLinearAttenuation
      (
      const double num
      );

   ///
   /// \brief setQuadAttenuation Setter for quadAttenuation property.
   /// \param sets num to quadradic attenuation
   ///
   void setQuadAttenuation
      (
      const double num
      );

   ///
   /// \brief setSpotExponent Setter for spotExponent property.
   /// \param sets num to spotExponent
   ///
   void setSpotExponent
      (
      const double num
      );

   ///
   /// \brief setSpotCutoff Setter for spotCutoff property.
   /// \param sets num to spotCutoff
   ///
   void setSpotCutoff
      (
      const double num
      );

Q_SIGNALS:
   ///
   /// \brief lightNumChanged Signal emitted when the lightNum is changed via this object.
   /// \param num for  lightNum.
   ///
   void lightNumChanged
      (
      int num
      );



   ///
   /// \brief ambientChangedSignal emitted when the ambient property is changed via this object.
   /// \param for ambient
   ///
   void ambientChanged
      (
      const QVector4D vect
      );

   ///
   /// \brief diffuseChanged Signal emitted when the diffuse property is changed via this object.
   /// \param for diffuse
   ///
   void diffuseChanged
      (
      const QVector4D vect
      );

   ///
   /// \brief specularChanged Signal emitted when the specular property is changed via this object.
   /// \param for specular
   ///
   void specularChanged
      (
      const QVector4D vect
      );

   ///
   /// \brief positionChanged Signal emitted when the position property is changed via this object.
   /// \param for position
   ///
   void positionChanged
      (
      const QVector4D vect
      );

   ///
   /// \brief directionChanged Signal emitted when the direction property is changed via this object.
   /// \param for direction
   ///
   void directionChanged
      (
      const QVector3D vect
      );


   ///
   /// \brief constAttenuationChanged Signal emitted when the constAttenuation property is changed via this object.
   /// \param for constant attenuation
   ///
   void constAttenuationChanged
      (
      const double num
      );

   ///
   /// \brief linearAttenuationChanged Signal emitted when the linearAttenuation property is changed via this object.
   /// \param for linear attenuation
   ///
   void linearAttenuationChanged
      (
      const double num
      );

   ///
   /// \brief quadAttenuationChanged Signal emitted when the quadAttenuation property is changed via this object.
   /// \param for quadradic attenuation
   ///
   void quadAttenuationChanged
      (
      const double num
      );

   ///
   /// \brief spotExponentChanged Signal emitted when the spotExponent property is changed via this object.
   /// \param for spotExponent
   ///
   void spotExponentChanged
      (
      const double num
      );

   ///
   /// \brief spotCutoffChanged Signal emitted when the spotCutoff property is changed via this object.
   /// \param for spotCutoff
   ///
   void spotCutoffChanged
      (
      const double num
      );

};




#endif // LightQtQml_H

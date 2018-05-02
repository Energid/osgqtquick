//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file ShadowMapQtQml.cpp
/// @class ShadowMapQtQml
//
//------------------------------------------------------------------------------
#include "shadowmap.hpp"
#include "shadowmapindex.hpp"

#include <osgQtQml/Index>
#include <osgShadow/ShadowMap>

#include <osg/Vec4>
#include <osg/Vec2>
#include <osg/Vec3d>
#include <QtGui/QColor>
#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>


/// \brief Provides functions to convert between Qt and OSG data types.
/// \ingroup Ec_Qml_OsgCore
namespace OsgQtConversionTemp
{
   ///
   /// \brief toOsg Converts a QColor to osg::Vec4 (OSG color).
   /// \param color QColor
   /// \return Color as osg::Vec4.
   ///
   inline /*OSGQTQML_EXPORT*/ const osg::Vec4 toOsg
      (
      const QColor& color
      )
   {
      return osg::Vec4(color.redF(), color.greenF(), color.blueF(), color.alphaF());
   }

   ///
   /// \brief toQt Converts a color on osg (osg::Vec4) to a QColor value
   /// \param color osg::Vec4 value representing the color.
   /// \return QColor value.
   ///
   inline /*OSGQTQML_EXPORT*/ const QColor toQColor
      (
      const osg::Vec4& color
      )
   {
      return QColor::fromRgbF(color.r(), color.g(), color.b(), color.a());
   }

   ///
   /// \brief toOsg Converts a vector of QVector4D to equivalent osg vect3d  value
   /// \param vector QVector4D value.
   /// \return osg::Vec3d value.
   ///
   inline /*OSGQTQML_EXPORT*/ osg::Vec4 toOsg
      (
      const QVector4D &vect
      )
   {
      return osg::Vec4(vect[0], vect[1], vect[2], vect[3]);
   }

   ///
   /// \brief toOsg Converts a vector of QVector4D to equivalent osg vect3d  value
   /// \param vector QVector4D value.
   /// \return osg::Vec3d value.
   ///
   inline /*OSGQTQML_EXPORT*/ osg::Vec2 toOsg
      (
      const QVector2D &vect
      )
   {
      return osg::Vec2(vect[0], vect[1]);
   }

   ///
   /// \brief toOsg Converts a vector of QVector3D to equivalent osg vect3d  value
   /// \param vector QVector3D value.
   /// \return osg::Vec3d value.
   ///
   inline /*OSGQTQML_EXPORT*/ osg::Vec3f toOsg
      (
      const QVector3D &vect
      )
   {
      return osg::Vec3f(vect[0], vect[1], vect[2]);
   }

   ///
   /// \brief QVector3D Converts a vector of osg::Vec3d to equivalent QVector3D  value
   /// \param vector osg::Vec3f value.
   /// \return QVector3D value.
   ///
   inline /*OSGQTQML_EXPORT*/ QVector3D toQt
      (
      const osg::Vec3f &vect
      )
   {
      return QVector3D(vect[0], vect[1], vect[2]);
   }

   ///
   /// \brief QVector3D Converts a vector of osg::Vec3d to equivalent QVector3D  value
   /// \param vector osg::Vec3d value.
   /// \return QVector3D value.
   ///
   inline /*OSGQTQML_EXPORT*/ QVector3D toQt
      (
      const osg::Vec3d &vect
      )
   {
      //return QVector3D(boost::numeric_cast<float>(vect[0]), boost::numeric_cast<float>(vect[1]), boost::numeric_cast<float>(vect[2]));

       return QVector3D((vect[0]), (vect[1]), (vect[2]));
   }

   /// \brief Returns a QVector4D by value for given osg::Vec4.
   inline /*OSGQTQML_EXPORT*/ QVector4D toQt
      (
      const osg::Vec4& vect
      )
   {
      return QVector4D(vect.x(), vect.y(), vect.z(), vect.w());
   }

   /// \brief Returns a QVector4D by value for given osg::Vec4.
   inline /*OSGQTQML_EXPORT*/ QVector2D toQt
      (
      const osg::Vec2& vect
      )
   {
      return QVector2D(vect.x(), vect.y());
   }
}


namespace osgShadow {

//------------------------------------------------------------------------------
ShadowMapQtQml::ShadowMapQtQml
   (
   QObject *parent
   ) :  ShadowTechniqueQtQml(parent)
{

}

//------------------------------------------------------------------------------
ShadowMapQtQml::ShadowMapQtQml
   (
   ShadowMapQtQml::Index* index,
   QObject* parent
   ) : ShadowTechniqueQtQml(index, parent)
{

}

//------------------------------------------------------------------------------
void ShadowMapQtQml::classBegin
   (
   )
{

    if(!i(this))
    {
       setI(new Index);
    }
    i(this)->setQ(this);
    ShadowTechniqueQtQml::classBegin();

}

//--------------------------------------------------------------------------
unsigned int ShadowMapQtQml::textureUnit
  (
  )const
{
   return o(this)->getTextureUnit();
}

//--------------------------------------------------------------------------
void ShadowMapQtQml::setTextureUnit
   (
   unsigned int unit
   )
{
   if(textureUnit() == unit)
   {
      return;
   }

   o(this)->setTextureUnit(unit);
   textureUnitChanged(unit);
}

//--------------------------------------------------------------------------
QVector2D ShadowMapQtQml::polygonOffset
   (
   )const
{
   return OsgQtConversionTemp::toQt(o(this)->getPolygonOffset());
}

//-------------------------------------------------------------------------
void ShadowMapQtQml::setPolygonOffset
   (
   QVector2D offsetVect
   )
{
    if(polygonOffset() == offsetVect)
    {
       return;
    }

    o(this)->setPolygonOffset(OsgQtConversionTemp::toOsg(offsetVect));
    polygonOffsetChanged(offsetVect);
}

//-------------------------------------------------------------
void ShadowMapQtQml::setAmbientBias
   (
   QVector2D ambientBiasVect
   )
{
   if(ambientBias() == ambientBiasVect)
   {
      return;
   }

   o(this)->setAmbientBias(OsgQtConversionTemp::toOsg(ambientBiasVect));
   ambientBiasChanged(ambientBiasVect);
}

//-------------------------------------------------------------
QVector2D ShadowMapQtQml::ambientBias
   (
   )const
{
   return OsgQtConversionTemp::toQt(o(this)->getAmbientBias());
}

//------------------------------------------------------------
void ShadowMapQtQml::setTextureSize
   (
   QVector2D textureSizeVect
   )
{
   if(textureSize() == textureSizeVect)
   {
      return;
   }

   //TODO
  // o(this)->setTextureSize(OsgQtConversionTemp::toOsg(textureSizeVect));
   textureSizeChanged(textureSizeVect);
}

//-------------------------------------------------------------
QVector2D ShadowMapQtQml::textureSize
   (
   )const
{
   return QVector2D();
   //return OsgQtConversionTemp::toQt(o(this)->getTextureSize());
}

//------------------------------------------------------------
void ShadowMapQtQml::setLight
   (
   osg::LightQtQml* pLight
   )
{
   o(this)->setLight(pLight->light());
}

//------------------------------------------------------------
void ShadowMapQtQml::setLight
   (
   osg::LightSourceQtQml* pLightSrc
   )
{
   o(this)->setLight(pLightSrc->lightSource());
}
}

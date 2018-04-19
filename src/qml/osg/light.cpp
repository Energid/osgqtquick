//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file LightQtQml.cpp
/// @class LightQtQml
//
//------------------------------------------------------------------------------
#include "light.hpp"
#include "lightindex.hpp"

#include "osgqtconversion.hpp"
#include <osgQtQml/Index>
#include <osg/Light>

//------------------------------------------------------------------------------
LightQtQml::LightQtQml
   (
   QObject *parent
   ) :  StateAttributeQtQml(parent)
{

}

//------------------------------------------------------------------------------
LightQtQml::LightQtQml
   (
   LightQtQml::Index* index,
   QObject* parent
   ) : StateAttributeQtQml(index, parent)
{

}

//------------------------------------------------------------------------------
void LightQtQml::classBegin
   (
   )
{

    if(!i(this))
    {
       setI(new Index);
    }
    i(this)->setQ(this);
    StateAttributeQtQml::classBegin();

}

//------------------------------------------------------------------------------
osg::Light* LightQtQml::light
   (
   )
{
   return o(this);
}

//------------------------------------------------------------------------------
LightQtQml *LightQtQml::fromLight
   (
   osg::Light *pLight,
   QObject *pParent
   )
{
   if(!pLight)
   {
      return 0;
   }

   if(osgQtQml::Index *index = osgQtQml::Index::checkIndex(pLight))
   {
      return static_cast<LightQtQml*>(index->qtObject());
   }

   LightQtQml *pResult = new LightQtQml(new Index(pLight), pParent);
   pResult->classBegin();

   return pResult;
}

//------------------------------------------------------------------------------
const int LightQtQml::lightNum
   (
   ) const
{
   return o(this)->getLightNum();
}


//------------------------------------------------------------------------------
void LightQtQml::setLightNum
   (
   const int num
   )
{
   if(lightNum() == num)
   {
      return;
   }

   o(this)->setLightNum(num);
   lightNumChanged(num);
}


//------------------------------------------------------------------------------
const QVector4D LightQtQml::ambient
   (
   )const
{
   return OsgQtConversion::toQt(o(this)->getAmbient());
}

//------------------------------------------------------------------------------
void LightQtQml::setAmbient
   (
   const QVector4D vect
   )
{
   if(ambient() == vect)
   {
      return;
   }
   osg::Vec4 osgVec = OsgQtConversion::toOsg(vect);
   o(this)->setAmbient(osgVec);
   ambientChanged(vect);

}

//------------------------------------------------------------------------------
const QVector4D LightQtQml::diffuse
   (
   )const
{
   return OsgQtConversion::toQt(o(this)->getDiffuse());
}

//------------------------------------------------------------------------------
void LightQtQml::setDiffuse
   (
   const QVector4D vect
   )
{
   if(diffuse() == vect)
   {
      return;
   }
   osg::Vec4 osgVec = OsgQtConversion::toOsg(vect);
   o(this)->setDiffuse(osgVec);
   diffuseChanged(vect);

}

//------------------------------------------------------------------------------
const QVector4D LightQtQml::specular
   (
   )const
{
   return OsgQtConversion::toQt(o(this)->getSpecular());
}

//------------------------------------------------------------------------------
void LightQtQml::setSpecular
   (
   const QVector4D vect
   )
{
   if(specular() == vect)
   {
      return;
   }
   osg::Vec4 osgVec = OsgQtConversion::toOsg(vect);
   o(this)->setSpecular(osgVec);
   specularChanged(vect);

}

//------------------------------------------------------------------------------
const QVector4D LightQtQml::position
   (
   )const
{
   return OsgQtConversion::toQt(o(this)->getPosition());
}

//------------------------------------------------------------------------------
void LightQtQml::setPosition
   (
   const QVector4D vect
   )
{
   if(position() == vect)
   {
      return;
   }
   osg::Vec4 osgVec = OsgQtConversion::toOsg(vect);
   o(this)->setPosition(osgVec);
   positionChanged(vect);

}

//------------------------------------------------------------------------------
const QVector3D LightQtQml::direction
   (
   )const
{
   return OsgQtConversion::toQt(o(this)->getDirection());
}

//------------------------------------------------------------------------------
void LightQtQml::setDirection
   (
   const QVector3D vect
   )
{
   if(direction() == vect)
   {
      return;
   }
   osg::Vec3 osgVec = OsgQtConversion::toOsg(vect);
   o(this)->setDirection(osgVec);
   directionChanged(vect);

}

//------------------------------------------------------------------------------
const double LightQtQml::constAttenuation
   (
   )const
{
   return o(this)->getConstantAttenuation();
}

//------------------------------------------------------------------------------
void LightQtQml::setConstAttenuation
   (
   const double num
   )
{
   if(constAttenuation() == num)
   {
      return;
   }

   o(this)->setConstantAttenuation(num);
   constAttenuationChanged(num);

}

//------------------------------------------------------------------------------
const double LightQtQml::linearAttenuation
   (
   )const
{
   return o(this)->getLinearAttenuation();
}

//------------------------------------------------------------------------------
void LightQtQml::setLinearAttenuation
   (
   const double num
   )
{
   if(linearAttenuation() == num)
   {
      return;
   }

   o(this)->setLinearAttenuation(num);
   linearAttenuationChanged(num);

}


//------------------------------------------------------------------------------
const double LightQtQml::quadAttenuation
   (
   )const
{
   return o(this)->getQuadraticAttenuation();
}

//------------------------------------------------------------------------------
void LightQtQml::setQuadAttenuation
   (
   const double num
   )
{
   if(quadAttenuation() == num)
   {
      return;
   }

   o(this)->setQuadraticAttenuation(num);
   quadAttenuationChanged(num);

}

//------------------------------------------------------------------------------
const double LightQtQml::spotExponent
   (
   )const
{
   return o(this)->getSpotExponent();
}

//------------------------------------------------------------------------------
void LightQtQml::setSpotExponent
   (
   const double num
   )
{
   if(spotExponent() == num)
   {
      return;
   }

   o(this)->setSpotExponent(num);
   spotExponentChanged(num);

}

//------------------------------------------------------------------------------
const double LightQtQml::spotCutoff
   (
   )const
{
   return o(this)->getSpotCutoff();
}

//------------------------------------------------------------------------------
void LightQtQml::setSpotCutoff
   (
   const double num
   )
{
   if(spotCutoff() == num)
   {
      return;
   }

   o(this)->setSpotCutoff(num);
   spotCutoffChanged(num);

}


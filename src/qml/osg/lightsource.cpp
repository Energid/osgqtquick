//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file LightSource.cpp
/// @class LightSourceQtQml
//
//------------------------------------------------------------------------------
#include "lightsource.hpp"
#include "lightsourceindex.hpp"
#include "light.hpp"

#include "osgqtconversion.hpp"

#include <osg/LightSource>

namespace osg {

//------------------------------------------------------------------------------
LightSourceQtQml::LightSourceQtQml
   (
   QObject *parent
   ) :  osg::GroupQtQml(parent),
    m_pLightObject(0),
    m_LocalStateSetModes(osg::StateAttribute::ON)
{

}

//------------------------------------------------------------------------------
LightSourceQtQml::LightSourceQtQml
   (
   LightSourceQtQml::Index* index,
   QObject* parent
   ) : osg::GroupQtQml(index, parent)
{

}

//------------------------------------------------------------------------------
void LightSourceQtQml::classBegin
   (
   )
{

   if(!i(this))
   {
      setI(new Index);
   }
   i(this)->setQ(this);
   osg::GroupQtQml::classBegin();
   o(this)->setLocalStateSetModes(m_LocalStateSetModes);
}



//------------------------------------------------------------------------------
const QVariant LightSourceQtQml::light
   (
   ) const
{
   // o(this)->getLight();
   return QVariant::fromValue(m_pLightObject);
}


//------------------------------------------------------------------------------
void LightSourceQtQml::setLight
   (
   const QVariant lightObject
   )
{

   osg::LightQtQml* pObject = lightObject.value<osg::LightQtQml*>();
   if(pObject)
   {
      if(pObject == m_pLightObject)
      {
         return;
      }
      m_pLightObject = pObject;
      o(this)->setLight(m_pLightObject->light());
      lightChanged(QVariant::fromValue(m_pLightObject));
   }

}

//------------------------------------------------------------------------------
const quint16 LightSourceQtQml::localStateSetModes
   (
   )const
{
   return m_LocalStateSetModes;
}

//------------------------------------------------------------------------------
void LightSourceQtQml::setLocalStateSetModes
   (
   const quint16 mode
   )
{
   if(m_LocalStateSetModes == mode)
   {
      return;
   }
   m_LocalStateSetModes = mode;

   o(this)->setLocalStateSetModes(mode);
   localStateSetModesChanged(mode);

}

}

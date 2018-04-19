//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightindex.cpp
/// @class LightQtQmlIndex
//
//------------------------------------------------------------------------------
#include "lightindex.hpp"
#include <osg/Light>

#include "light.hpp"



//------------------------------------------------------------------------------
LightQtQml::Index::Index
   (
   osg::Light* pLightObject
   ) : StateAttributeQtQml::Index(pLightObject)
{

}

//------------------------------------------------------------------------------
void LightQtQml::Index::classBegin
   (
   )
{
   if(!o(this))
   {
      setO(new osg::Light);
   }
   StateAttributeQtQml::Index::classBegin();
}

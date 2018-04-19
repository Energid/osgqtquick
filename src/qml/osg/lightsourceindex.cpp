//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightsource.cpp
/// @class LightSourceQtQml
//
//------------------------------------------------------------------------------
#include "lightsourceindex.hpp"
#include <osg/LightSource>

#include "lightsource.hpp"


//------------------------------------------------------------------------------
LightSourceQtQml::Index::Index
   (
   osg::LightSource* pLightSourceObject
   ) : GroupQtQml::Index(pLightSourceObject)
{

}

//------------------------------------------------------------------------------
void LightSourceQtQml::Index::classBegin
   (
   )
{
   if(!o(this))
   {
      setO(new osg::LightSource);
   }
   GroupQtQml::Index::classBegin();
}

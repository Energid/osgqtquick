//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightindex.cpp
/// @class ShadowedSceneQtQmlIndex
//
//------------------------------------------------------------------------------
#include "shadowedsceneindex.hpp"
#include <osgShadow/ShadowedScene>

#include "shadowedscene.hpp"

#include <osgQtQml/Index>

namespace osgShadow {

//------------------------------------------------------------------------------
ShadowedSceneQtQml::Index::Index
   (
   osgShadow::ShadowedScene* pLightObject
   ) : GroupQtQml::Index(pLightObject)
{

}

//------------------------------------------------------------------------------
void ShadowedSceneQtQml::Index::classBegin
   (
   )
{
   if(!o(this))
   {
      setO(new osgShadow::ShadowedScene );
   }
   GroupQtQml::Index::classBegin();
}

}

//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file ShadowMapindex.cpp
/// @class ShadowMapQtQmlIndex
//
//------------------------------------------------------------------------------
#include "ShadowMapindex.hpp"
#include <osgShadow/ShadowMap>

#include "ShadowMap.hpp"

#include <osgQtQml/Index>

namespace osgShadow {

//------------------------------------------------------------------------------
ShadowMapQtQml::Index::Index
   (
   osgShadow::ShadowMap* pLightObject
   ) : ShadowTechniqueQtQml::Index(pLightObject)
{

}

//------------------------------------------------------------------------------
void ShadowMapQtQml::Index::classBegin
   (
   )
{
   if(!o(this))
   {
      setO(new osgShadow::ShadowMap);
   }
   ShadowTechniqueQtQml::Index::classBegin();
}

}

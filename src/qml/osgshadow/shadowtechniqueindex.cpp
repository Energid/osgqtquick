//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file shadowtechniqueindex.cpp
/// @class ShadowTechniqueQtQmlIndex
//
//------------------------------------------------------------------------------
#include "shadowtechniqueindex.hpp"
#include <osgShadow/ShadowTechnique>

#include "shadowtechnique.hpp"

#include <osgQtQml/Index>

namespace osgShadow {

//------------------------------------------------------------------------------
ShadowTechniqueQtQml::Index::Index
   (
   osgShadow::ShadowTechnique* pLightObject
   ) : ObjectQtQml::Index(pLightObject)
{

}

//------------------------------------------------------------------------------
void ShadowTechniqueQtQml::Index::classBegin
   (
   )
{
   if(!o(this))
   {
      setO(new osgShadow::ShadowTechnique);
   }
   osg::ObjectQtQml::Index::classBegin();
}

}

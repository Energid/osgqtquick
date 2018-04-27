//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file ShadowTechniqueQtQml.cpp
/// @class ShadowTechniqueQtQml
//
//------------------------------------------------------------------------------
#include "shadowtechnique.hpp"
#include "shadowtechniqueindex.hpp"

#include <osgQtQml/Index>



namespace osgShadow {

//------------------------------------------------------------------------------
ShadowTechniqueQtQml::ShadowTechniqueQtQml
   (
   QObject *parent
   ) :  osg::ObjectQtQml(parent)
{

}

//------------------------------------------------------------------------------
ShadowTechniqueQtQml::ShadowTechniqueQtQml
   (
   ShadowTechniqueQtQml::Index* index,
   QObject* parent
   ) : osg::ObjectQtQml(index, parent)
{

}

//------------------------------------------------------------------------------
void ShadowTechniqueQtQml::classBegin
   (
   )
{

    if(!i(this))
    {
       setI(new Index);
    }
    i(this)->setQ(this);
    osg::ObjectQtQml::classBegin();

}

////------------------------------------------------------------------------------
osgShadow::ShadowTechnique* ShadowTechniqueQtQml::shadowTechnique
   (
   )
{
   return o(this);
}



}

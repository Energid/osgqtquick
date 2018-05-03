//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file ShadowedSceneQtQml.cpp
/// @class ShadowedSceneQtQml
//
//------------------------------------------------------------------------------
#include "shadowedscene.hpp"
#include "shadowedsceneindex.hpp"


#include <osgQtQml/Index>
#include <osg/Light>

namespace osgShadow {

//------------------------------------------------------------------------------
ShadowedSceneQtQml::ShadowedSceneQtQml
   (
   QObject *parent
   ) :  osg::GroupQtQml(parent)
{

}

//------------------------------------------------------------------------------
ShadowedSceneQtQml::ShadowedSceneQtQml
   (
   ShadowedSceneQtQml::Index* index,
   QObject* parent
   ) : osg::GroupQtQml(index, parent)
{

}

//------------------------------------------------------------------------------
void ShadowedSceneQtQml::classBegin
   (
   )
{

    if(!i(this))
    {
       setI(new Index);
    }
    i(this)->setQ(this);
    osg::GroupQtQml::classBegin();

}

//------------------------------------------------------------------------------
osgShadow::ShadowedScene* ShadowedSceneQtQml::shadowedScene
   (
   )
{
   return o(this);
}

//------------------------------------------------------------------------------
ShadowedSceneQtQml* ShadowedSceneQtQml::fromShadowedScene
   (
   osgShadow::ShadowedScene *pShadowedScene,
   QObject *pParent
   )
{
   if(!pShadowedScene)
   {
      return 0;
   }

   if(osgQtQml::Index *index = osgQtQml::Index::checkIndex(pShadowedScene))
   {
      return static_cast<ShadowedSceneQtQml*>(index->qtObject());
   }

   ShadowedSceneQtQml *pResult = new ShadowedSceneQtQml(new Index(pShadowedScene), pParent);
   pResult->classBegin();

   return pResult;
}
//------------------------------------------------------------------------------
osg::StateSetQtQml* ShadowedSceneQtQml::getOrCreateStateSet
   (
   )
{
   return osg::StateSetQtQml::fromStateSet(o(this)->getOrCreateStateSet());
}

//------------------------------------------------------------------------------
void ShadowedSceneQtQml::setShadowTechnique
   (
   ShadowTechniqueQtQml* technique
   )
{
   o(this)->setShadowTechnique(technique->shadowTechnique());
}

//------------------------------------------------------------------------------
void ShadowedSceneQtQml::setCastsShadowTraversalMask
   (
   unsigned int mask
   )
{
   if(castsShadowTraversalMask() == mask)
   {
      return;
   }

   o(this)->setCastsShadowTraversalMask(mask);
   castsShadowTraversalMaskChanged(mask);

}

//------------------------------------------------------------------------------
unsigned int ShadowedSceneQtQml::castsShadowTraversalMask
   (
   )const
{
   return o(this)->getCastsShadowTraversalMask();
}

//------------------------------------------------------------------------------
void ShadowedSceneQtQml::setReceivesShadowTraversalMask
   (
   unsigned int mask
   )
{
    if(receivesShadowTraversalMask() == mask)
    {
       return;
    }

    o(this)->setReceivesShadowTraversalMask(mask);
    receivesShadowTraversalMaskChanged(mask);
}

//------------------------------------------------------------------------------
unsigned int ShadowedSceneQtQml::receivesShadowTraversalMask
   (
   )const
{
   return o(this)->getReceivesShadowTraversalMask();
}

}

//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightmodel.cpp
/// @class LightModelQtQml
//
//------------------------------------------------------------------------------
#include "lightmodelindex.hpp"
#include <osg/LightModel>

#include "lightmodel.hpp"

namespace osg {
//------------------------------------------------------------------------------
LightModelQtQml::Index::Index
   (
   osg::LightModel* pLightModelObject
   ) : StateAttributeQtQml::Index(pLightModelObject)
{

}

//------------------------------------------------------------------------------
void LightModelQtQml::Index::classBegin
   (
   )
{
   if(!o(this))
   {
      setO(new osg::LightModel);
   }
   StateAttributeQtQml::Index::classBegin();
}

}

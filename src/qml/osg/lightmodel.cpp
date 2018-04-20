//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightmodel.cpp
/// @class LightModelQtQml
//
//------------------------------------------------------------------------------
#include "lightmodel.hpp"
#include "lightmodelindex.hpp"

#include "osgqtconversion.hpp"

#include <osgQtQml/Index>
#include <osg/LightModel>

namespace osg {

//------------------------------------------------------------------------------
LightModelQtQml::LightModelQtQml
   (
   QObject *parent
   ) :  StateAttributeQtQml(parent)
{

}

//------------------------------------------------------------------------------
LightModelQtQml::LightModelQtQml
   (
   LightModelQtQml::Index* index,
   QObject* parent
   ) : StateAttributeQtQml(index, parent)
{

}

//------------------------------------------------------------------------------
void LightModelQtQml::classBegin
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
const QVector4D LightModelQtQml::ambientIntensity
   (
   )const
{
   return OsgQtConversion::toQt(o(this)->getAmbientIntensity());
}

//------------------------------------------------------------------------------
void LightModelQtQml::setAmbientIntensity
   (
   const QVector4D vect
   )
{
   if(ambientIntensity() == vect)
   {
      return;
   }
   osg::Vec4 osgVec = OsgQtConversion::toOsg(vect);
   o(this)->setAmbientIntensity(osgVec);
   ambientIntensityChanged(vect);

}

//------------------------------------------------------------------------------
const bool LightModelQtQml::twoSided
   (
   )const
{
   return o(this)->getTwoSided();
}

//------------------------------------------------------------------------------
void LightModelQtQml::setTwoSided
   (
   const bool flag
   )
{
   if(twoSided() == flag)
   {
      return;
   }
   o(this)->setTwoSided(flag);
   twoSidedChanged(flag);

}

//------------------------------------------------------------------------------
const bool LightModelQtQml::localViewer
   (
   )const
{
   return o(this)->getLocalViewer();
}

//------------------------------------------------------------------------------
void LightModelQtQml::setLocalViewer
   (
   const bool flag
   )
{
   if(localViewer() == flag)
   {
      return;
   }
   o(this)->setLocalViewer(flag);
   localViewerChanged(flag);

}

}

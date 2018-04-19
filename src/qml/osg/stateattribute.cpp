//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file stateattribute.cpp
/// @class StateAttributeQtQml
//
//------------------------------------------------------------------------------
#include "stateattribute.hpp"
#include "stateattributeindex.hpp"

#include "osgqtconversion.hpp"

#include <osgQtQml/Index>
#include <osg/StateAttribute>

//------------------------------------------------------------------------------
StateAttributeQtQml::StateAttributeQtQml
   (
   QObject *parent
   ) :  osg::ObjectQtQml(parent)
{

}

//------------------------------------------------------------------------------
StateAttributeQtQml::StateAttributeQtQml
   (
   StateAttributeQtQml::Index* index,
   QObject* parent
   ) : osg::ObjectQtQml(index, parent)
{

}


//------------------------------------------------------------------------------
osg::StateAttribute* StateAttributeQtQml::StateAttribute
   (
   )
{
   return o(this);
}



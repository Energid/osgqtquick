//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightindex.h
/// @class ShadowMapQtQmlIndex
//
//------------------------------------------------------------------------------
#ifndef ShadowMapQtQmlIndex_H
#define ShadowMapQtQmlIndex_H


#include "shadowmap.hpp"

#include <osgShadow/ShadowMap>

#include "shadowtechniqueindex.hpp"

#include <osgShadow/ShadowTechnique>

namespace osgShadow {

class ShadowMapQtQml;
///
/// \brief Index class for API mapping between ShadowMapQtQml and osg::Light.
///
class OSGQTQML_EXPORT ShadowMapQtQml::Index :
   public ShadowTechniqueQtQml::Index
{
public:
   typedef osgShadow::ShadowMap OType;
   typedef ShadowMapQtQml QType;
   friend class ShadowMapQtQml;

public:

   /// Constructor
   Index
      (
      osgShadow::ShadowMap  *pObject = 0
      );

   /// Executes when component initialization begins.
   void classBegin
      (
      );

};

}

#endif // ShadowMapQtQmlIndex_H

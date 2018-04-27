//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightindex.h
/// @class ShadowTechniqueQtQmlIndex
//
//------------------------------------------------------------------------------
#ifndef ShadowTechniqueQtQmlIndex_H
#define ShadowTechniqueQtQmlIndex_H


#include "shadowtechnique.hpp"

#include <osgShadow/ShadowTechnique>

#include <osg/ObjectQtQmlIndex>

namespace osgShadow {

class ShadowTechniqueQtQml;
///
/// \brief Index class for API mapping between ShadowTechniqueQtQml and osg::Light.
///
class OSGQTQML_EXPORT ShadowTechniqueQtQml::Index :
   public ObjectQtQml::Index
{
public:
   typedef osgShadow::ShadowTechnique OType;
   typedef ShadowTechniqueQtQml QType;
   friend class ShadowTechniqueQtQml;

public:

   /// Constructor
   Index
      (
      osgShadow::ShadowTechnique  *pObject = 0
      );

   /// Executes when component initialization begins.
   void classBegin
      (
      );

};

}

#endif // ShadowTechniqueQtQmlIndex_H

//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file ShadowTechniqueQtQml.hpp
/// @class ShadowTechniqueQtQml
//
//------------------------------------------------------------------------------
#ifndef ShadowTechniqueQtQml_H
#define ShadowTechniqueQtQml_H

#include <osg/ObjectQtQml>

#include <osg/Object>
#include <osgShadow/ShadowTechnique>

#include <QtGui/QVector4D>
#include <QtGui/QVector3D>

namespace osgShadow {
///
/// \brief The ShadowTechniqueQtQml class wraps the ShadowTechnique item/class provided by the
/// Osg framework.
///
/// \details It wraps an instance of osgShadow::ShadowTechnique and exposes necessary API from it in QML.
///
/// \qmltype{ShadowTechniqueQtQml}
/// \ingroup
class OSGQTQML_EXPORT ShadowTechniqueQtQml :
    public osg::ObjectQtQml
{
   Q_OBJECT


public:
    class Index;

    ///
    /// \brief ShadowTechniqueQtQml default constructor
    /// \param parent Parent QObject/Item
    ///
    explicit ShadowTechniqueQtQml
       (
       QObject *parent = 0
       );

    ///
    /// \brief ShadowTechniqueQtQml constructor
    /// \param index Initial ShadowTechniqueQtQml index (Object mapping between OSG and QML types for Camera).
    /// \param parent Parent QObject/Item.
    ///
    ShadowTechniqueQtQml
       (
       ShadowTechniqueQtQml::Index *index,
       QObject *parent = 0
       );

    void classBegin
       (
       );

    osgShadow::ShadowTechnique* shadowTechnique();

public Q_SLOTS:



Q_SIGNALS:



};

}


#endif // ShadowTechniqueQtQml_H

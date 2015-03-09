///
/// AtmosphereComponentRenderer.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 8 Mar 2015
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Renders atmosphere components
///

#pragma once

#ifndef AtmosphereComponentRenderer_h__
#define AtmosphereComponentRenderer_h__

#include <Vorb/ecs/ECS.h>
#include <Vorb/ecs/ComponentTable.hpp>
#include <Vorb/VorbPreDecl.inl>
#include <Vorb/graphics/gtypes.h>

DECL_VG(class GLProgram)

struct AtmosphereComponent;
struct SpaceLightComponent;
class SpaceSystem;
class Camera;

class AtmosphereComponentRenderer {
public:
    AtmosphereComponentRenderer();
    ~AtmosphereComponentRenderer();

    void draw(const AtmosphereComponent& aCmp,
              const Camera* camera,
              const f32v3& relCamPos,
              const f32v3& lightDir,
              const SpaceLightComponent* spComponent,
              f32 planetRadius);
private:
    void buildShaders();
    void buildMesh();

    vg::GLProgram* m_program = nullptr;
    VGBuffer m_icoVbo = 0;
    VGIndexBuffer m_icoIbo = 0;
    int m_numIndices = 0;
};

#endif // AtmosphereComponentRenderer_h__


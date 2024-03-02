#pragma once

#include "components/simple_scene.h"
#include "components/transform.h"
#include <vector>
#include <glm/glm.hpp>

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        Tema2();
        ~Tema2();

        void Init() override;
        

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color = glm::vec3(1));

        void OnInputUpdate(float deltaTime, int mods) override;
        void RotateTank(float deltaTime, float rotationSpeed);
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        glm::vec3 lightPosition;
        glm::vec3 sina1pos;
        glm::vec3 sina2pos;
        glm::vec3 corppos;
        glm::vec3 turelapos;
        glm::vec3 tunpos;

        glm::vec3 c1pos;
        glm::vec3 c2pos;
        glm::vec3 c3pos;
        glm::vec3 c4pos;
        glm::vec3 c5pos;
        glm::vec3 c6pos;

        float tankRotationAngle=0.0f;
        unsigned int materialShininess;
        float materialKd;
        float materialKs;
        glm::vec3 tankDirection = glm::vec3(0.0f, 0.0f, -1.0f);
        struct Bullet {
            glm::vec3 position;
            glm::vec3 direction;
            float speed;
            float lifetime;
        };
        std::vector<Bullet> bullets;

        float turretRotationAngle = 0.0f;

        float gameTime = 0.0f;

        struct Enemy {
            glm::vec3 position;
            float speed;
            glm::vec3 randomDestination;
            float changeDestinationTime;
            float rotationAngle;
            glm::vec3 direction;
            float changeDirectionInterval;
        };
        std::vector<Enemy> enemies;

        float COLLISION_THRESHOLD = 1.0f;

        float timeSinceLastShot = 0.0f;

        glm::vec3 cameraOffset = glm::vec3(2, -5, -4);
        float cameraAngle = 0.0f;
    };
}   // namespace m1
